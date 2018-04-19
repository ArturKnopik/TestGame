////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Error code
///
////////////////////////////////////////////////////////////

int main()
{
    // Open a connection with the X server
    Display* display = XOpenDisplay(NULL);
    if (!display)
        return EXIT_FAILURE;

    // Get the default screen
    int screen = DefaultScreen(display);

    // Let's create the main window
    XSetWindowAttributes attributes;
    attributes.background_pixel = BlackPixel(display, screen);
    attributes.event_mask       = KeyPressMask;
    Window window = XCreateWindow(display, RootWindow(display, screen),
                                  0, 0, 650, 330, 0,
                                  DefaultDepth(display, screen),
                                  InputOutput,
                                  DefaultVisual(display, screen),
                                  CWBackPixel | CWEventMask, &attributes);
    if (!window)
        return EXIT_FAILURE;

    // Set the window's name
    XStoreName(display, window , "SFML Window");

    // Let's create the windows which will serve as containers for our SFML views
    Window view1 = XCreateWindow(display, window,
                                 10, 10, 310, 310, 0,
                                 DefaultDepth(display, screen),
                                 InputOutput,
                                 DefaultVisual(display, screen),
                                 0, NULL);
    Window view2 = XCreateWindow(display, window,
                                 330, 10, 310, 310, 0,
                                 DefaultDepth(display, screen),
                                 InputOutput,
                                 DefaultVisual(display, screen),
                                 0, NULL);

    // Show our windows
    XMapWindow(display, window);
    XFlush(display);

    // Create our SFML views
    sf::Window sfmlView1(view1);
    sf::Window sfmlView2(view2);

    // Create a clock for measuring elapsed time
    sf::Clock clock;

    // Initialize our views
    initialize(sfmlView1);
    initialize(sfmlView2);

    // Start the event loop
    bool running = true;
    while (running)
    {
        while (XPending(display))
        {
            // Get the next pending event
            XEvent event;
            XNextEvent(display, &event);

            // Process it
            switch (event.type)
            {
                // Any key is pressed: quit
                case KeyPress:
                    running = false;
                    break;
            }
        }

        // Draw something into our views
        draw(sfmlView1, clock.getElapsedTime().asSeconds());
        draw(sfmlView2, clock.getElapsedTime().asSeconds() * 0.3f);

        // Display the views on screen
        sfmlView1.display();
        sfmlView2.display();
    }

    // Close the display
    XCloseDisplay(display);

    return EXIT_SUCCESS;
}
