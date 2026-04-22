#include<iostream>

struct Building {
    int left;
    int right;
    int height;
};

struct Point {
    int x;
    int y;
};

int mergeSkylines(Point* sky1, int n1, Point* sky2, int n2, Point* out) {
    int h1 = 0, h2 = 0;
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        int x, maxh;
        if (sky1[i].x < sky2[j].x) {
            x = sky1[i].x;
            h1 = sky1[i].y;
            maxh = (h1 > h2) ? h1 : h2;
            i++;
        } else if (sky1[i].x > sky2[j].x) {
            x = sky2[j].x;
            h2 = sky2[j].y;
            maxh = (h1 > h2) ? h1 : h2;
            j++;
        } else {
            x = sky1[i].x;
            h1 = sky1[i].y;
            h2 = sky2[j].y;
            maxh = (h1 > h2) ? h1 : h2;
            i++; 
            j++;
        }

        if (k == 0 || out[k - 1].y != maxh) {
            if (k > 0 && out[k - 1].x == x) {
                out[k - 1].y = (out[k - 1].y > maxh) ? out[k - 1].y : maxh;
            } else {
                out[k].x = x;
                out[k].y = maxh;
                k++;
            }
        }
    }

    while (i < n1) {
        if (k == 0 || out[k - 1].y != sky1[i].y) {
            if (k > 0 && out[k - 1].x == sky1[i].x) {
                out[k - 1].y = (out[k - 1].y > sky1[i].y) ? out[k - 1].y : sky1[i].y;
            } else {
                out[k++] = sky1[i];
            }
        }
        i++;
    }

    while (j < n2) {
        if (k == 0 || out[k - 1].y != sky2[j].y) {
            if (k > 0 && out[k - 1].x == sky2[j].x) {
                out[k - 1].y = (out[k - 1].y > sky2[j].y) ? out[k - 1].y : sky2[j].y;
            } else {
                out[k++] = sky2[j];
            }
        }
        j++;
    }

    return k; 
}

int getSkyline(Building* b, int start, int end, Point* out) {
    if (start == end) {
        out[0].x = b[start].left;
        out[0].y = b[start].height;
        out[1].x = b[start].right;
        out[1].y = 0;
        return 2;
    }

    int mid = start + (end - start) / 2;
    
    int max_pts_left = 2 * (mid - start + 1);
    int max_pts_right = 2 * (end - mid);
    
    Point* leftSky = new Point[max_pts_left];
    Point* rightSky = new Point[max_pts_right];

    int n1 = getSkyline(b, start, mid, leftSky);
    int n2 = getSkyline(b, mid + 1, end, rightSky);

    int n_out = mergeSkylines(leftSky, n1, rightSky, n2, out);

    delete[] leftSky;
    delete[] rightSky;

    return n_out;
}

int main() {
    int n;
    std::cout << "Enter number of buildings: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "No buildings." << std::endl;
        return 0;
    }

    Building* b = new Building[n];
    for (int i = 0; i < n; i++) {
        std::cout << "Building " << i + 1 << " (left right height): ";
        std::cin >> b[i].left >> b[i].right >> b[i].height;
    }

    Point* out = new Point[2 * n];
    
    int num_points = getSkyline(b, 0, n - 1, out);

    std::cout << "\nSkyline Contour Points (x, y):" << std::endl;
    for (int i = 0; i < num_points; i++) {
        std::cout << "[" << out[i].x << ", " << out[i].y << "]" << std::endl;
    }

    delete[] b;
    delete[] out;
    return 0;
}