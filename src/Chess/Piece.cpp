//
// Created by Arch on 20/11/2024.
//

#include "Piece.h"

Piece::Piece(Type typeSet, Faction factionSet):type(typeSet),faction(factionSet)
{
}

Piece::Piece():type(Type_Empty),faction(Faction_Empty)
{
}

Piece::~Piece()
{

}


