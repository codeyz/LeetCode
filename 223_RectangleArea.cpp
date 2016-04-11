class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        int areaOfRec = (D - B) * (C - A) + (H - F) * (G - E);
        int overlap = 0;
        if(!(A >= G || F >= D || B >= H || E >= C))
        {
            overlap = (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
        }
        return areaOfRec - overlap;
    }
};
