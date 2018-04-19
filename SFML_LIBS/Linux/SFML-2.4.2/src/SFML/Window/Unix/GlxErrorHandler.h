#ifndef _GLXERRORHANDLER_H
#define _GLXERRORHANDLER_H


class GlxErrorHandler {
  public:
    inline GlxErrorHandler(::Display * display) :
            m_lock   (glxErrorMutex),
            m_display(display)
            {
                glxErrorOccurred = false;
                m_previousHandler = XSetErrorHandler(HandleXError);
            };

    inline ~GlxErrorHandler() {
                XSync(m_display, False);
                XSetErrorHandler(m_previousHandler);
            };


  private:
    sf::Lock m_lock;

    ::Display * m_display;

    
            int      (*m_previousHandler)(::Display*, XErrorEvent*);

};
#endif
