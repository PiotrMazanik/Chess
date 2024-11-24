//
// Created by Arch on 23/11/2024.
//

#ifndef CELLSCAN_H
#define CELLSCAN_H



class ScannedCell {
    public:
    enum cell_type
    {
        blank,
        selectedCell,
        canMoveTo,
        CanCapture,
        canCastle,
        CanPass
    };

    ScannedCell(cell_type type, int x, int y);
    ~ScannedCell();

    const int Get_X(){return x;}
    const int Get_Y(){return y;}
    const cell_type Get_Type(){return type;}



    private:
    cell_type type;
    int x;
    int y;


};



#endif //CELLSCAN_H
