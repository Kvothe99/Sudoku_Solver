/* This is a struct that will hold a sudoku */

#include<array>

class Sudoku_obj
{
public:
  /**
   * Constructor
   *
   * Makes all the numbers in the sudoku 0.
   **/
  Sudoku_obj();
  /**
   * get
   *
   * Returns a refrence to the location given if it works. On fail
   * it returns null.
   **/
  uint8_t& get(uint8_t col, uint8_t row);
private:
  std::array<char, 81> m_array;
};

Sudoku_obj::Sudoku_obj()
{
  m_array.fill(0);
}

uint8_t& Sudoku_obj::get(uint8_t col, uint8_t row)
{
  return m_array.at(col + (row * 9));
}

