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
        Bishop,
        Knight,
        Rook,
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

    Type GetType(){return type;}
    Faction GetFaction(){return faction;}

private:
    Type type;
    Faction faction;
};



#endif //PIECE_H
