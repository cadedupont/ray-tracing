#include <iostream>

int main() {
    const int width = 256;
    const int height = 256;

    std::cout << "P3\n" << width << " " << height << "\n255\n";

    for (int i = height - 1; i >= 0; --i) {
        for (int j = 0; j < width; ++j) {
            float r = float(j) / float(width - 1);
            float g = float(i) / float(height - 1);
            float b = 0.25f;

            int ir = int(255.999f * r);
            int ig = int(255.999f * g);
            int ib = int(255.999f * b);

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    return EXIT_SUCCESS;
}