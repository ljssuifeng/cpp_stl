#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
#include <string>

struct Student {
  std::string name;
  int score;

  bool operator<(const Student& other_student) {
    return score != other_student.score ? score > other_student.score
                                        : name < other_student.name;
  }
  friend std::ostream& operator<<(std::ostream& out, const Student& student);
};

std::ostream& operator<<(std::ostream& out, const Student& student) {
  out << student.name << ": " << student.score << std::endl;
  return out;
}

#endif
