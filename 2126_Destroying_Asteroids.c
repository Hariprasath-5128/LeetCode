int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

bool asteroidsDestroyed(int mass, int* asteroids, int asteroidsSize) {
    /* Sort asteroids */
    qsort(asteroids, asteroidsSize, sizeof(int), compare);

    long new_mass = (long)mass;
    bool possible = true;

    for(int i = 0; i < asteroidsSize; i++) {
        if(new_mass >= asteroids[i]) {
            new_mass += asteroids[i];
        }
        else {
            possible = false;
            break;
        }
    }
    return possible;
}
