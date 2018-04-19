#ifndef _NETWORKRECORDER_H
#define _NETWORKRECORDER_H


#include "typedef3.h"

////////////////////////////////////////////////////////////
/// Specialization of audio recorder for sending recorded audio
/// data through the network
////////////////////////////////////////////////////////////
class NetworkRecorder : public typedef3 {
  public:
    ////////////////////////////////////////////////////////////
    /// Constructor
    ///
    /// \param host Remote host to which send the recording data
    /// \param port Port of the remote host
    ///
    ////////////////////////////////////////////////////////////
    inline NetworkRecorder(const sf::IpAddress & host, unsigned short port) :
        m_host(host),
        m_port(port)
        {
        };

    ////////////////////////////////////////////////////////////
    /// Destructor
    ///
    /// \see SoundRecorder::~SoundRecorder()
    ///
    ////////////////////////////////////////////////////////////
    inline ~NetworkRecorder() {
            // Make sure to stop the recording thread
            stop();
        };


  private:
    ////////////////////////////////////////////////////////////
    /// \see SoundRecorder::onStart
    ///
    ////////////////////////////////////////////////////////////
    inline virtual bool onStart() {
            if (m_socket.connect(m_host, m_port) == sf::Socket::Done)
            {
                std::cout << "Connected to server " << m_host << std::endl;
                return true;
            }
            else
            {
                return false;
            }
        };

    ////////////////////////////////////////////////////////////
    /// \see SoundRecorder::onProcessSamples
    ///
    ////////////////////////////////////////////////////////////
    inline virtual bool onProcessSamples(const sf::Int16 * samples, std::size_t sampleCount) {
            // Pack the audio samples into a network packet
            sf::Packet packet;
            packet << audioData;
            packet.append(samples, sampleCount * sizeof(sf::Int16));
    
            // Send the audio packet to the server
            return m_socket.send(packet) == sf::Socket::Done;
        };

    ////////////////////////////////////////////////////////////
    /// \see SoundRecorder::onStop
    ///
    ////////////////////////////////////////////////////////////
    inline virtual void onStop() {
            // Send a "end-of-stream" packet
            sf::Packet packet;
            packet << endOfStream;
            m_socket.send(packet);
    
            // Close the socket
            m_socket.disconnect();
        };

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    ///< Address of the remote host
    sf::IpAddress m_host;

    ///< Remote port
    unsigned short m_port;

    ///< Socket used to communicate with the server
    sf::TcpSocket m_socket;

};
#endif
