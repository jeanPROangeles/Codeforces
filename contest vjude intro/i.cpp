    #include <bits/stdc++.h>
    using namespace std;

    bool isValidHowl(const string& howl) {
        bool foundO = false;
        for (size_t i = 0; i < howl.length(); ++i) {
            char current = howl[i];
            char next = (i < howl.length() - 1) ? howl[i + 1] : '\0';
            
            if (current == 'A' && foundO) return false;  
            if (current == 'O') foundO = true;
            if (current == 'W' && next == 'W') return false; 
            if (current == 'H' && (next == 'H' || next == 'W' || next == 'A')) return false; 
        }   
        return true; 
    }

    string makeLongerHowl(std::string fenrir_howl) {
        string prefix = "AHOW"; 
        string longer_howl = prefix + fenrir_howl;

        
        if (!isValidHowl(longer_howl)) {
            longer_howl = fenrir_howl + "OOA"; 
        }

        return longer_howl;
    }

    int main() {
        string fenrir_howl;
        cin >> fenrir_howl;

        string my_howl = makeLongerHowl(fenrir_howl);
        
        cout << my_howl << endl;
        
        return 0;
    }
