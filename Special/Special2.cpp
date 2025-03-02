#include <iostream>
#include <vector>
#include <cmath>

struct point{
    float x = 0.f;
    float y = 0.f;
};

struct line{
    point begin;
    point end;
};

struct triangle{
    point points[3];
    line lines[3];
};

struct polygon{
    triangle trianglesIn[2];
};


bool onLine(const point first, const point second, const point third) 
{ 
    if (second.x <= std::max(first.x, third.x) && second.x >= std::min(first.x, third.x) && 
        second.y <= std::max(first.y, third.y) && second.y >= std::min(first.y, third.y)){
            return true;
    } 
    return false; 
} 


int vecOrient(const point first, const point second, const point third) 
{
    float val = (second.y - first.y) * (third.x - second.x) - 
                (second.x - first.x) * (third.y - second.y); 
    if (val == 0.f){
        return 0;
    }
    return (val > 0.f) ? 1 : -1;
}


bool checkCross(const line line1, const line line2){
    int or1 = vecOrient(line1.begin, line1.end, line2.begin);
    int or2 = vecOrient(line1.begin, line1.end, line2.end);
    int or3 = vecOrient(line2.begin, line2.end, line1.begin);
    int or4 = vecOrient(line2.begin, line2.end, line1.end);
    if(or1 != or2 && or3 != or4){
        return true;
    }
    if(or1 == 0 && onLine(line1.begin, line2.begin, line1.end)){
        return true;
    }else if(or2 == 0 && onLine(line1.begin, line2.end, line1.end)){
        return true;
    }else if(or3 == 0 && onLine(line2.begin, line1.begin, line2.end)){
        return true;
    }else if(or4 == 0 && onLine(line2.begin, line1.end, line2.end)){
        return true;
    }
    return false;
}


void crossPoint(const line line1, const line line2, std::vector <point> &crossPoints){
    point A = line1.begin;
    point B = line1.end;
    point C = line2.begin;
    point D = line2.end;
    point cross = {0.f, 0.f};

    float k1 = 0.f;
    float k2 = 0.f;
    float b1 = 0.f;
    float b2 = 0.f;

    if(A.x >= B.x){
        point change = A;
        A = B;
        B = change;
    }
    if(C.x >= D.x){
        point change = C;
        C = D;
        D = change;
    }
    if(A.y != B.y){
        if(B.x == A.x){
            cross.x == A.x;
        }else{
            k1 = (B.y - A.y) / (B.x - A.x);
        }
    }
    if(C.y != D.y){
        if(D.x == C.x){
            cross.x == C.x;
        }else{
            k2 = (D.y - C.y) / (D.x - C.x);
        }
    }

    b1 = A.y - k1 * A.x;
    b2 = C.y - k2 * C.x;

    if(k1 == k2 && b1 == b2){
        point cross1;
        point cross2;
        if(A.x >= C.x && B.x <= D.x){
            cross1 = A;
            cross2 = B;
        }else if(A.x >= C.x && B.x > D.x){
            cross1 = A;
            cross2 = D;
        }else if(A.x < C.x && B.x <= D.x){
            cross1 = C;
            cross2 = B;
        }else if(A.x < C.x && B.x > D.x){
            cross1 = C;
            cross2 = D;
        }
        for(int i = 0; i < 2; i++){
            int count = 0;
            point check;
            for(int j = 0; j < crossPoints.size(); j++){
                if(i == 0){
                    check = cross1;
                }else if(i == 1){
                    check = cross2;
                }
                if(check.x == crossPoints[i].x && check.y == crossPoints[i].y){
                    count++;
                    break;
                }
            }
            if(count == 0){
                crossPoints.push_back(check);
            }
        }
    }else if(A.x == B.x && B.x == C.x && C.x == D.x){
        point cross1;
        point cross2;
        if(A.x >= C.x && B.x <= D.x){
            cross1 = A;
            cross2 = B;
        }else if(A.x >= C.x && B.x > D.x){
            cross1 = A;
            cross2 = D;
        }else if(A.x < C.x && B.x <= D.x){
            cross1 = C;
            cross2 = B;
        }else if(A.x < C.x && B.x > D.x){
            cross1 = C;
            cross2 = D;
        }
        for(int i = 0; i < 2; i++){
            int count = 0;
            point check;
            for(int j = 0; j < crossPoints.size(); j++){
                if(i == 0){
                    check = cross1;
                }else if(i == 1){
                    check = cross2;
                }
                if(check.x == crossPoints[i].x && check.y == crossPoints[i].y){
                    count++;
                    break;
                }
            }
            if(count == 0){
                crossPoints.push_back(check);
            }
        }
    }else{
        if(cross.x != 0.f){
            cross.x = (b2 - b1) / (k1 - k2);
            cross.y = k1 * A.x + b1;
        }else{
            cross.y = k2 * C.x + b2;
        }
        int count = 0;
        for(int i = 0; i < crossPoints.size(); i++){
            if(cross.x == crossPoints[i].x && cross.y == crossPoints[i].y){
                count++;
            }
        }
        if(count == 0){
            crossPoints.push_back(cross);
        }
    }
}


void checkEqual(const polygon triangles, std::vector <point> crossPoints){
    bool checkPointX1[3];
    bool checkPointY1[3];
    bool checkPointX2[3];
    bool checkPointY2[3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(triangles.trianglesIn[0].points[i].x == triangles.trianglesIn[1].points[j].x && 
               triangles.trianglesIn[0].points[i].y == triangles.trianglesIn[1].points[j].y &&
               !checkPointX1[i] && !checkPointY1[i] && !checkPointX2[j] && !checkPointY2[j]){
                crossPoints.push_back(triangles.trianglesIn[0].points[i]);
                checkPointX1[i];
                checkPointY1[i];
                checkPointX2[j];
                checkPointY2[j];
            }
        }
    }
}


bool checkInside(const point pointIn, const triangle triang){
    float a = (triang.points[0].x - pointIn.x) * (triang.points[1].y - triang.points[0].y) - 
              (triang.points[1].x - triang.points[0].x) * (triang.points[0].y - pointIn.y);
    float b = (triang.points[1].x - pointIn.x) * (triang.points[2].y - triang.points[1].y) - 
              (triang.points[2].x - triang.points[1].x) * (triang.points[1].y - pointIn.y);
    float c = (triang.points[2].x - pointIn.x) * (triang.points[0].y - triang.points[2].y) - 
              (triang.points[0].x - triang.points[2].x) * (triang.points[2].y - pointIn.y);
    if(a > 0 && b > 0 && c > 0 || a < 0 && b < 0 && c < 0){
        return true;
    }
    return false;
}


void polygonSort(std::vector <point> &crossPoints){
    std::vector <point> crossPointIn;
    point beg = crossPoints[0];
    for(int i = 1; i < crossPoints.size(); i++){
        if(beg.x >= crossPoints[i].x){
            beg = crossPoints[i];
        }
    }
    for(int i = 1; i < crossPoints.size(); i++){
        if(beg.x == crossPoints[i].x){
            if(crossPoints[i].y >= beg.y){
                beg = crossPoints[i];
            }
        }
    }
}

int main(){
    std::cout << "Input coordinates of triangles\n";
    polygon triangles;
    std::vector <point> crossPoints;

    for(int i = 0; i < 2; i++){
        std::cout << i + 1 << " triangle: ";
        for(int j = 0; j < 3; j++){
            std::cin >> triangles.trianglesIn[i].points[j].x >> triangles.trianglesIn[i].points[j].y;
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            triangles.trianglesIn[i].lines[j].begin = triangles.trianglesIn[i].points[j];
            triangles.trianglesIn[i].lines[j].end = triangles.trianglesIn[i].points[(j + 1) % 3];
        }
    }

    checkEqual(triangles, crossPoints);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(checkCross(triangles.trianglesIn[0].lines[i], triangles.trianglesIn[0].lines[j])){
                crossPoint(triangles.trianglesIn[0].lines[i], triangles.trianglesIn[0].lines[j], crossPoints);
            }
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(checkInside(triangles.trianglesIn[0].points[j], triangles.trianglesIn[1])){
                int count = 0;
                for(int k = 0; k < crossPoints.size(); k++){
                    if(triangles.trianglesIn[0].points[j].x == crossPoints[k].x && 
                       triangles.trianglesIn[0].points[j].y == crossPoints[k].y){
                        count++;
                        break;
                    }
                }
                if(count == 0){
                    crossPoints.push_back(triangles.trianglesIn[0].points[j]);
                }
            }
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(checkInside(triangles.trianglesIn[1].points[j], triangles.trianglesIn[0])){
                int count = 0;
                for(int k = 0; k < crossPoints.size(); k++){
                    if(triangles.trianglesIn[1].points[j].x == crossPoints[k].x && 
                       triangles.trianglesIn[1].points[j].y == crossPoints[k].y){
                        count++;
                        break;
                    }
                }
                if(count == 0){
                    crossPoints.push_back(triangles.trianglesIn[1].points[j]);
                }
            }
        }
    }

    polygonSort(crossPoints);

    return 0;
}
    