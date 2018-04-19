#ifndef _CONNECTIONCACHE_H
#define _CONNECTIONCACHE_H


struct ConnectionCache {
    inline ConnectionCache() : connected(false) {};

    bool connected;

    sf::Clock timer;

};
#endif
