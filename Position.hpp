class Position {
    protected :
        int x, y;
    public:
        Position();
        Position(int coordinate_x, int coordinate_y);
        Position(const Position&);
        void setPosition(int a, int b);
};