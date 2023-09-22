int minDistance(string word1, string word2) {
    int a[word1.size() + 1][word2.size() + 1]; 
    for(int i = 0; i < word1.size(); i++){
        a[i][word2.size()] = word1.size() - i;
    }
    for(int j = 0; j < word2.size(); j++){
        a[word1.size()][j] = word2.size() - j; 
    }
    a[word1.size()][word2.size()] = 0; 
    for(int i = word1.size() - 1; i >= 0; i--){
        for(int j = word2.size() - 1; j >= 0; j--){
            if(word1[i] == word2[j]){
                a[i][j] = a[i + 1][j + 1]; 
            }
            else a[i][j] = 1 + min({a[i][j + 1], a[i + 1][j], a[i + 1][j + 1]}); 
        }
    }
    return a[0][0]; 
}