////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////

int main()
{
    // Play a sound
    playSound();

    // Play music from an ogg file
    playMusic("orchestral.ogg");

    // Play music from a flac file
    playMusic("ding.flac");

    // Wait until the user presses 'enter' key
    std::cout << "Press enter to exit..." << std::endl;
    std::cin.ignore(10000, '\n');

    return EXIT_SUCCESS;
}
