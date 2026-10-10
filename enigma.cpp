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
        int npos;

        std::array<int, 26> wiring;
        std::array<int, 26> back_wiring;

    public:
        rotors(std::array<int,26> w, int n = -1){
            wiring = w;
            npos = n;
            position = 0;


            for (int i = 0; i < 26 ; i++){
                int j = wiring[i];
                back_wiring[j] = i;
            }
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
        int backward(int input){
            int enter = (input + position) % 26;
            int wire = back_wiring[enter];
            int exit = (wire - position + 26) % 26;
            return exit;
        }
        int pos(){
            return position;
        }
        bool is_npos(){
            return position == npos;
        }
    };


void run(std::string text){
    std::array<int, 26> w_rotos1 = {6,0,5,3,1,9,18,13,23,21,17,16,10,8,22,11,14,12,15,4,19,24,7,20,2,25};
    std::array<int, 26> w_rotos2 = {5,12,2,24,11,4,17,9,22,8,1,21,20,0,13,7,18,16,14,19,15,23,25,10,6,3};
    std::array<int, 26> w_rotos3 = {5,19,1,9,22,8,7,17,2,0,15,23,20,6,3,11,18,14,13,4,10,16,12,24,21,25};
    std::array<int, 26> b_r = {
    24, 17, 20, 7, 16, 18, 11, 3, 15, 23, 13, 6, 14, 
    10, 12, 8, 4, 1, 5, 25, 2, 22, 21, 9, 0, 19
};
    

    rotors r1(w_rotos1, 16);
    rotors r2(w_rotos2, 4);
    rotors r3(w_rotos3, 21);
    rotors br(b_r,-1);
    for (int i = 0; i < text.length(); i++){
        int letter = text[i] - 'A';

        if (r2.is_npos()){
            r2.step();
            r3.step();
        }
        else if(r1.is_npos()){
            r2.step();

        }
        r1.step();
    
        int x1 = r1.forward(letter);
        int x2 = r2.forward(x1);
        int x3 = r3.forward(x2);
        
        int reflected = br.forward(x3);
        
        int b3 = r3.backward(reflected);
        int b2 = r2.backward(b3);
        int b1 = r1.backward(b2);

        // std::cout << r3.pos();
        // std::cout << " ";
        // std::cout << r2.pos();
        // std::cout << " ";
        // std::cout << r1.pos();
        // std::cout << " ";
        std::cout << (char)(b1 + 'A');
    };
}
int main() {
    run("OUFPOILEQSFHKJKXURIYL");
    std::cout << std::endl;

    return 0;
}