////////////////////////////////////////////////////////////

void main(ActivityStates* states)
{
    // Initialize the thread before giving the hand
    initializeMain(states);

    sleep(seconds(0.5));
    ::main(0, NULL);

    // Terminate properly the main thread and wait until it's done
    terminateMain(states);

    {
        Lock lock(states->mutex);

        states->terminated = true;
    }

    return NULL;
}
