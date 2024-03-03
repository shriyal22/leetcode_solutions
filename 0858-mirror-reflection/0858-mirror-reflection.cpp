class Solution {
public:
    int findGCD(int a, int b){
        int loop = min(a, b);
        while(loop){
            if(a%loop == 0 && b%loop == 0) break;
            loop--;
        }
        return loop;
    }
    int mirrorReflection(int p, int q) {
        int gcd = findGCD(p, q);
        p = p/gcd;
        q=q/gcd;
        if(q==p) return 1;
        if(p%2 == 0) return 2;
        else {
            if(q%2 == 0) return 0;
            else return 1;
        }
    }
};