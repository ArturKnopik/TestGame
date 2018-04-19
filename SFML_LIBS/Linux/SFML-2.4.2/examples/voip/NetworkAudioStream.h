#ifndef _NETWORKAUDIOSTREAM_H
#define _NETWORKAUDIOSTREAM_H


#include "typedef4.h"

////////////////////////////////////////////////////////////
/// Customized sound stream for acquiring audio data
/// from the network
////////////////////////////////////////////////////////////
class NetworkAudioStream : public typedef4 {
  public:
    ////////////////////////////////////////////////////////////
    /// Default constructor
    ///
    ////////////////////////////////////////////////////////////
    inline NetworkAudioStream() :
        m_offset     (0),
        m_hasFinished(false)
        {
            // Set the sound parameters
            initialize(1, 44100);
        };

    ////////////////////////////////////////////////////////////
    /// Run the server, stream audio data from the client
    ///
    ////////////////////////////////////////////////////////////
    inline void start(unsigned short port) {
            if (!m_hasFinished)
            {
                // Listen to the given port for incoming connections
                if (m_listener.listen(port) != sf::Socket::Done)
                    return;
                std::cout << "Server is listening to port " << port << ", waiting for connections... " << std::endl;
    
                // Wait for a connection
                if (m_listener.accept(m_client) != sf::Socket::Done)
                    return;
                std::cout << "Client connected: " << m_client.getRemoteAddress() << std::endl;
    
                // Start playback
                play();
    
                // Start receiving audio data
                receiveLoop();
            }
            else
            {
                // Start playback
                play();
            }
        };


  private:
    ////////////////////////////////////////////////////////////
    /// /see SoundStream::OnGetData
    ///
    ////////////////////////////////////////////////////////////
    inline virtual bool onGetData(sf::SoundStream::Chunk & data) {
            // We have reached the end of the buffer and all audio data have been played: we can stop playback
            if ((m_offset >= m_samples.size()) && m_hasFinished)
                return false;
    
            // No new data has arrived since last update: wait until we get some
            while ((m_offset >= m_samples.size()) && !m_hasFinished)
                sf::sleep(sf::milliseconds(10));
    
            // Copy samples into a local buffer to avoid synchronization problems
            // (don't forget that we run in two separate threads)
            {
                sf::Lock lock(m_mutex);
                m_tempBuffer.assign(m_samples.begin() + m_offset, m_samples.end());
            }
    
            // Fill audio data to pass to the stream
            data.samples     = &m_tempBuffer[0];
            data.sampleCount = m_tempBuffer.size();
    
            // Update the playing offset
            m_offset += m_tempBuffer.size();
    
            return true;
        };

    ////////////////////////////////////////////////////////////
    /// /see SoundStream::OnSeek
    ///
    ////////////////////////////////////////////////////////////
    inline virtual void onSeek(sf::Time timeOffset) {
            m_offset = timeOffset.asMilliseconds() * getSampleRate() * getChannelCount() / 1000;
        };

    ////////////////////////////////////////////////////////////
    /// Get audio data from the client until playback is stopped
    ///
    ////////////////////////////////////////////////////////////
    inline void receiveLoop() {
            while (!m_hasFinished)
            {
                // Get waiting audio data from the network
                sf::Packet packet;
                if (m_client.receive(packet) != sf::Socket::Done)
                    break;
    
                // Extract the message ID
                sf::Uint8 id;
                packet >> id;
    
                if (id == audioData)
                {
                    // Extract audio samples from the packet, and append it to our samples buffer
                    const sf::Int16* samples     = reinterpret_cast<const sf::Int16*>(static_cast<const char*>(packet.getData()) + 1);
                    std::size_t      sampleCount = (packet.getDataSize() - 1) / sizeof(sf::Int16);
    
                    // Don't forget that the other thread can access the sample array at any time
                    // (so we protect any operation on it with the mutex)
                    {
                        sf::Lock lock(m_mutex);
                        std::copy(samples, samples + sampleCount, std::back_inserter(m_samples));
                    }
                }
                else if (id == endOfStream)
                {
                    // End of stream reached: we stop receiving audio data
                    std::cout << "Audio data has been 100% received!" << std::endl;
                    m_hasFinished = true;
                }
                else
                {
                    // Something's wrong...
                    std::cout << "Invalid packet received..." << std::endl;
                    m_hasFinished = true;
                }
            }
        };

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    
    sf::TcpListener m_listener;

    sf::TcpSocket m_client;

    sf::Mutex m_mutex;

    std::vector<sf::Int16> m_samples;

    std::vector<sf::Int16> m_tempBuffer;

    std::size_t m_offset;

    bool m_hasFinished;

};
#endif
