#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

void decryptMessage(string message, string freqLang);

int main(int argc, char* argv[])
{
    string message =
        "Bgc-bfufb tegaedppqna ql aggv zge xof tegaedppfe'l lgjb.\nXof adpf vflqanfe logjbvn'x hf pdwqna d cgebv qn coqro xof tbdkfe ql mjlx d lpdbb tdex. Xof tbdkfe QL XOF HGLL; qx'l kgje vjxk xg fnxfexdqn oqp ge ofe.\n\nZgrjl ql d pdxxfe gz vfrqvqna codx xoqnal kgj def ngx agqna xg vg.\n\nXof rglx gz dvvqna d zfdxjef qln'x mjlx xof xqpf qx xdwfl xg rgvf qx. Xof rglx dblg qnrbjvfl xof dvvqxqgn gz dn ghlxdrbf xg zjxjef fstdnlqgn. Xof xeqrw ql xg tqrw xof zfdxjefl xodx vgn'x zqaox fdro gxofe. - Mgon Rdepdrw. (ccc.adpdljxed.rgp/uqfc/nfcl/234346?utkjpvbjr)\n\n(ccc.hedqnkijgxf.rgp/ijgxfl/djxogel/m/mgon_rdepdrw.oxpb)";
    string freqLang = "TEOAISRHNUCMDLGWFPYKJBVQX";
    
    decryptMessage(message, freqLang);

    return 0;
}

void decryptMessage(string message, string freqLang)
{
    // Count letter frequency
    unordered_map<char, int> frequencyMap;
    for (char c : message)
    {
        if (isalpha(c))
        {
            frequencyMap[static_cast<char>(tolower(c))]++;
        }
    }
    /* Debug for frequency map
    for (auto frequency_map : frequencyMap)
    {
        cout << "Letter: " << frequency_map.first << " Frequency: " << frequency_map.second << endl;
    }*/

    //Order letters by frequency
    string sortedLetters;
    for (const auto& pair : frequencyMap)
    {
        sortedLetters += pair.first;
    }
    sort(sortedLetters.begin(), sortedLetters.end(), [&frequencyMap](char a, char b) { return frequencyMap[a] > frequencyMap[b]; });

    /* Debug for sorted Letters
    cout << sortedLetters << endl;
    cout << freqLang << endl;*/
    
    // Create decryption Map 
    unordered_map<char, char> decryptionMap;
    for (size_t i = 0; i < freqLang.size(); ++i)
    {
        decryptionMap[sortedLetters[i]] = freqLang[i];
    }

    /* Debug for decryption Map 
    for (auto decryption_map : decryptionMap)
    {
        cout << "Letter: " << decryption_map.first << " with frequency " << frequencyMap[decryption_map.first] << " decrypted to: " << decryption_map.second << endl;
    }*/
    
    // Use decryption Map to decrypt message
    string decryptedMessage;
    for (char c : message)
    {
        if (isalpha(c)) // Only decrypt alpha characters     
        {
            char cLower = static_cast<char>(tolower(c));
            if (islower(c))
            {
                decryptedMessage += static_cast<char>(tolower(decryptionMap[cLower]));
            }
            else
            {
                decryptedMessage += static_cast<char>(toupper(decryptionMap[cLower]));
            }
        }
        else
        {
            decryptedMessage += c;
        }
    }

    cout << decryptedMessage << endl;
}
