#include <iostream>
#include <string>
#include <array>

class plugborad
{
private:
    std::array<int, 26> wiring;

public:
    plugborad()
    {
        for (int i = 0; i < 26; ++i)
        {
            wiring[i] = i;
        }
    }
    void connect(char l_a, char l_b)
    {
        int index_a = l_a - 'A';
        int index_b = l_b - 'A';

        wiring[index_a] = index_b;
        wiring[index_b] = index_a;
        
    }
    void show(){
        for(int i = 0 ; i < 26 ; ++i){
            std::cout << (char)(wiring[i] + 'A') << ' ' ;
        }
    }
};

class rotors{
    private:
        int position = 0;

        std::array<int, 26> wiring;
        public:
        rotors(std::array<int,26> w){
            wiring = w;
            position = 0;
        }
        void step(){
            position = (position + 1) % 26;

        }
        int forward(int input){
            int enter = (input + position) % 26;
            int wire = wiring[enter];
            int exit = (wire - position + 26) % 26;
            return exit;
        }
        int pos(){
            return position;
        }
    };
    
    
    int main()
    {
        std::array<int, 26> w_rotos1 = {6,0,5,3,1,9,18,13,23,21,17,16,10,8,22,11,14,12,15,4,19,24,7,20,2,25};
        std::array<int, 26> w_rotos2 = {5,12,2,24,11,4,17,9,22,8,1,21,20,0,13,7,18,16,14,19,15,23,25,10,6,3};
        std::array<int, 26> w_rotos3 = {5,19,1,9,22,8,7,17,2,0,15,23,20,6,3,11,18,14,13,4,10,16,12,24,21,25};
        std::array<int, 26> b_r = {23,5,15,10,24,8,4,9,17,16,11,12,2,3,1,20,18,7,6,14,25,0,21,19,22,13};
        rotors r1(w_rotos1);
        std::cout << r1.forward(1) << std::endl;
        r1.step();
        std::cout << r1.forward(1) << std::endl;
        r1.step();
        std::cout << r1.forward(1) << std::endl;
        r1.step();
        std::cout << r1.forward(1) << std::endl;
        r1.step();
        std::cout << r1.forward(1) << std::endl;
        return 0;
    }