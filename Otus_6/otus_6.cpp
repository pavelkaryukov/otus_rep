#include "big_number.h"
#include "matrix.h"
#include <set>

void Test() {
    Matrix<int, 0> matrix;
    matrix[std::vector<std::uint8_t>{0xbc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}][std::vector<std::uint8_t>{0xf3, 0xf2, 0xf1, 0xff, 0xf5, 0xf6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}] = 13;
    matrix[std::vector<std::uint8_t>{0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}][std::vector<std::uint8_t>{0xf3, 0xf2, 0xf1, 0xff, 0xf5, 0xf6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}] = 22;
    matrix[std::vector<std::uint8_t>{0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}][std::vector<std::uint8_t>{0xf3, 0xf2, 0xf1, 0xff, 0xf5, 0xf6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}] = 22;
    matrix[std::vector<std::uint8_t>{0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}][std::vector<std::uint8_t>{0xf3, 0xf2, 0xf1, 0xff, 0xf5, 0xf6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}] = 32;
    //ASSERT_EQ(matrix.size(), 1);
    matrix[std::vector<std::uint8_t>{0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}][std::vector<std::uint8_t>{0xf3, 0xf2, 0xf1, 0xff, 0xf5, 0xf6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}] = 0;
    matrix[std::vector<std::uint8_t>{0xbc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}][std::vector<std::uint8_t>{0xf3, 0xf2, 0xf1, 0xff, 0xf5, 0xf6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}] = 0;
    matrix[std::vector<std::uint8_t>{0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}][std::vector<std::uint8_t>{0xf3, 0xf2, 0xf1, 0xff, 0xf5, 0xf6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}] = 0;

    //ASSERT_EQ(matrix.size(), 0);


    BigNumber bn11{ std::uint32_t {0x10fd} };
    BigNumber bn33 = BigNumber({ 0x22, 0x33 });// ������� ���� ��������

    BigNumber bn2{ std::uint32_t{0xfd} };
    BigNumber bn3{ std::uint8_t {0xff} };
    BigNumber bn4{ std::uint32_t{0xff} };

//     std::set<BigNumber> testMap;
//     testMap.insert(bn1);
//     testMap.insert(bn2);
//     testMap.insert(bn3);
//     testMap.insert(bn4);
// 
// 

    int stop1 = 0;
}

int main() {
    //Test();
    Matrix <int, 0> matrix;
    const std::size_t startPos = 0;
    const std::size_t endPos = 9;
    for (auto i = startPos; i <= endPos; ++i) {
        matrix[i][i] = i;
        matrix[i][endPos - i] = endPos - i;
    }

    std::cout << "matrix fragment [1,1] for [8,8];" << std::endl;
    for (std::size_t i = 1; i <= 8; ++i) {
        for (std::size_t j = 1; j <= 8; ++j) {
            std::cout << boost::format("%1% ") % matrix[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << boost::format("Matrix size = %1%") % matrix.size() << std::endl;
    std::cout << "Matrix cout: " << std::endl;
    for (const auto elem : matrix) {
        const auto[x, y, v] = elem;
        int stop1 = 0;
        std::cout << boost::format("[%1%][%2%] = %3%") % x % y % v << std::endl;
    }
    ((matrix[100][100] = 314) = 0) = 217;
    assert(matrix[100][100] == 217);
    return 0;
}
//�������� ������
//1
//2