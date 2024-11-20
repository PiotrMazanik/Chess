//
// Created by Arch on 20/11/2024.
//

#ifndef PIECE_H
#define PIECE_H



class Piece {
    public:
    enum Type
    {
        Type_Empty,
        King,
        Queen,
        Rook,
        Bishop,
        Knight,
        Pawn
    };

    enum Faction
    {
        Faction_Empty,
        Black,
        White
    };

public:
    Piece(Type,Faction);
    Piece();
    ~Piece();

private:
    Type type;
    Faction faction;
};



#endif //PIECE_H
