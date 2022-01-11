#include <gtest/gtest.h>
#include <cmath> // fabs

#include "vector.h"

/**
 * @brief Return true if both parameters are (approximately) equal 
 * @param[in] number1 First number to compare
 * @param[in] number2 Second number to compare
 * @param[in] epsilon Precision for the comparison. It defaults
 * @see https://www.tutorialspoint.com/floating-point-comparison-in-cplusplus
 * @see https://stackoverflow.com/a/17341/12791643
 */
bool AreEqual(const double number1, const double number2, const double epsilon = 1e-10) {
  const bool result = fabs(number1 - number2) <= ((fabs(number1) < fabs(number2) ? fabs(number2) : fabs(number1)) * epsilon);
  // if (result == false) {  // Para depuración
  //   std::cout << std::setprecision(20);
  //   std::cout << "Epsilon:    " << epsilon << std::endl;
  //   std::cout << "Número1:    " << number1 << std::endl;
  //   std::cout << "Número2:    " << number2 << std::endl;
  //   std::cout << "Difference: " << fabs(number1 - number2) << std::endl;
  // }
  return result;
}

/**
 * Test para probar los constructores de la clase
 */
TEST(VectorTest, constructor) {
  Vector my_vector;

  EXPECT_EQ(true, AreEqual(my_vector.x(), 0.0));
  EXPECT_EQ(true, AreEqual(my_vector.y(), 0.0));
  EXPECT_EQ(true, AreEqual(my_vector.z(), 0.0));

  Vector another_vector{1.0, 2.0, 3.0};
  EXPECT_EQ(true, AreEqual(another_vector.x(), 1.0));
  EXPECT_EQ(true, AreEqual(another_vector.y(), 2.0));
  EXPECT_EQ(true, AreEqual(another_vector.z(), 3.0));
}

// Incluya tests adicionales para el resto de métodos de la clase


/**
 * Test que prueba si dos vectores son iguales
 * Hay que sobrecargar el operador de igualdad para comprobar este código
 */

/*
TEST(VectorTest, iguales) {
    Vector v1{1.0, 2.0, 3.0};
    Vector v2{1.0, 2.0, 3.0};
    Vector v3{4.0, 5.0, 6.0};

    EXPECT_EQ(true, v1 == v2);
    EXPECT_EQ(false, v1 == v3);
}
*/
