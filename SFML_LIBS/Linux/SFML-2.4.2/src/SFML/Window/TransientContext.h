#ifndef _TRANSIENTCONTEXT_H
#define _TRANSIENTCONTEXT_H


#include "typedef8.h"

// This structure contains all the state necessary to
// track TransientContext usage
struct TransientContext : private typedef8 {
    ////////////////////////////////////////////////////////////
    /// \brief Constructor
    ///
    ////////////////////////////////////////////////////////////
    inline TransientContext() :
            referenceCount   (0),
            context          (0),
            sharedContextLock(0),
            useSharedContext (false)
            {
                if (resourceCount == 0)
                {
                    context = new sf::Context;
                }
                else if (!currentContext)
                {
                    sharedContextLock = new sf::Lock(mutex);
                    useSharedContext = true;
                    sharedContext->setActive(true);
                }
            };

    ////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ////////////////////////////////////////////////////////////
    inline ~TransientContext() {
                if (useSharedContext)
                    sharedContext->setActive(false);
    
                delete sharedContextLock;
                delete context;
            };

    ///////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    
    unsigned int referenceCount;

    sf::Context * context;

    sf::Lock * sharedContextLock;

    bool useSharedContext;

};
#endif
