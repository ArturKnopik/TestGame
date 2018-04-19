#ifndef SF_PRIV_SOCKETINITIALIZER_H
#define SF_PRIV_SOCKETINITIALIZER_H


namespace sf {

namespace priv {

////////////////////////////////////////////////////////////
// Windows needs some initialization and cleanup to get
// sockets working properly... so let's create a class that will
// do it automatically
////////////////////////////////////////////////////////////
struct SocketInitializer {
    inline SocketInitializer() {
            WSADATA init;
            WSAStartup(MAKEWORD(2, 2), &init);
        };

    inline ~SocketInitializer() {
            WSACleanup();
        };

};

} // namespace sf::priv

} // namespace sf
#endif
