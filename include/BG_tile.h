//
// Created by jensp on 31/12/2024.
//

#ifndef AP_BG_TILE_H
#define AP_BG_TILE_H
namespace dj {
class BG_tile {
protected:
    int x_coord;
    int y_coord;

public:
    BG_tile() = default;
    BG_tile(int x, int y);

    /*
     *
     * return: x_coord
     *
     */
    [[nodiscard]] int getXCoord() const;

    /*
     *
     * return: Y_coord
     *
     */
    [[nodiscard]] int getYCoord() const;

    /*
     * moves relative to its current position
     *
     */
    void relativeMove(int xValue, int yValue);

    /*
     * moves to the new coordinates
     *
     */
    void absoluteMove(int newX, int newY);

    /*
     *
     * times up the background tile, lowers it depending on the difference in height
     * and moves it back up if it goes below the screen
     *
     */
    void time_up(int height);
};
} // namespace dj
#endif // AP_BG_TILE_H
