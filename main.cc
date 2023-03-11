#include "vector.hpp"

template <typename T>
bool Wall(Vec<T> v) {
    Vec<T> block[] = {
        {1, 1},
        {1, 2},
        {3, 0},
    };
    for (size_t i = 0; i < std::size(block); i++) {
        if (v == block[i]) {
            return true;
        }
    }
    return false;
}

void solve(Vec<int> *coord, int start, int end, Vec<int> &npc) {
    if (end - start == 0) {
        Vec<int> solusi = coord[end];
        if (norm(npc, solusi) == 1 and not Wall(solusi)) {
            npc = solusi;
            std::cout << "npc : maju ke koordinat " 
                      << solusi << std::endl;
        }
        return;
    }
    int mid = (start + end) / 2;
    solve(coord, start, mid, npc);
    solve(coord, mid + 1, end, npc);
}

int main() {
    Vec<int> koordinat[16] = {
        {0, 0}, {0, 1}, {0, 2}, {0, 3}, 
        {1, 0}, {1, 1}, {1, 2}, {1, 3},
        {2, 0}, {2, 1}, {2, 2}, {2, 3}, 
        {3, 0}, {3, 1}, {3, 2}, {3, 3},
    };
    Vec<int> npc = Vec<int>{0, 0};
    Vec<int> player = Vec<int>{3, 3};
    solve(koordinat, 0, 15, npc);
    if (npc == player) {
        std::cout << "npc berhasil bertemu player pada " 
                  << npc << std::endl;
    }
    return 0;
}
