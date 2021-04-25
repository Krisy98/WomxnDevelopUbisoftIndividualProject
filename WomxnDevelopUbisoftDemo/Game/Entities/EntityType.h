#pragma once

// sorted by dangerosity level
enum class FlowerType {
    Anemone,
    Hyacinth,
    Pansy,
    Rose,
    Delphinium
};

// sorted by dangerosity level
static const char* flowerStr[] = { 
    "Anemone",
    "Hyacinth",
    "Pansy",
    "Rose",
    "Delphinium"
};

const int nbFlower = 5;

enum class InsectType { Aphid, Cricket, LadyBirdBeetles, Worms };

// different behavior
enum class BossType { a, b, c};