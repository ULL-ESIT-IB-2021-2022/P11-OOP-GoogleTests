/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 13 2021
 * @brief Person class Definition
 *
 * @see https://www.learncpp.com/cpp-tutorial/header-guards/
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <string>

/**
 * Clase Persona. 
 *       Representa una persona usando su nombre, apellidos y edad
 */
class Persona {
 public:
  Persona(const std::string& nombre);
 private:
  std::string nombre_{""};     /** Almacena el nombre de la persona */
};
 
#endif
