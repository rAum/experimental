// This code is from 12.07.2012, when I was young and not very wise.
// It presents little fun I had when bored at my first job.

#include <iostream>

const int II = 0;
 
/// An 1D or 2D literal
class _ALiteral
{
public:
 _ALiteral() : width(1), height(0) {}
 
 int len() const { return width; }
 int len2() const { return height; }
 float ratio() const { return static_cast<float>(width) / height; }
 int area() const { return width * height; }
 
 // so we can write uint t = I---I; instead of (I---I).len()
 operator int() { return len(); }
 
 _ALiteral operator-(const _ALiteral& right) const {
   _ALiteral t;
   t.width = width + (right.width-1);
   t.height = right.height + height;
   return t;
 }
 
 _ALiteral& operator--(int) {
  width += 1;
  return *this;
 }
 
 _ALiteral operator | (_ALiteral right) {
   height = 1 + right.height;
   height >>= 1; 
   return *this;
 }
 
 _ALiteral& operator!() {
    height += 1;
    return *this;
 }
 
private:
 int width, height;
};
 
#define I _ALiteral()

int main(int, char**) {
 for (int worm = I-------------I; worm >= II; worm -= I-I ) {
    std::cout << '*';
}
 
uint monsterHP =  I-----------------------I;       // 12 HP
uint monBossHP = (I-----------------------I) * 10; // 120 HP

std::cout << "\nmonster hp: " << monsterHP << " boss hp: " << monBossHP << std::endl;
std::cout << "Area: \n";
std::cout <<( I-------I
              |       !
              !       !
              I-------I ).area() << std::endl; 
return 0;
}
