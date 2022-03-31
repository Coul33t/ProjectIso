namespace Tools {
    template<typename T>
    double dst(mVec2<T> p1, mVec2<T> p2) {
        if (pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) != 0)
            return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) * 1.0);

        return 0;
    }
}
