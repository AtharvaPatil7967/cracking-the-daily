class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x_closet = 0;
        int y_closet = 0;

        x_closet = max(x1, min(xCenter, x2));
        y_closet = max(y1, min(yCenter, y2));

        int dist1 = (x_closet - xCenter) * (x_closet - xCenter);
        int dist2 = (y_closet - yCenter) * (y_closet - yCenter);

        int dist = dist1 + dist2;

        if(dist <= (radius * radius))
        {
            return true;
        }

        return false;
    
    }
};