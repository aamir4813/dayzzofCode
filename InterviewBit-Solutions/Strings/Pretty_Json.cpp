string doIndent(int cnt){
    
    string temp = "";
    for(int i =0 ; i < cnt ;++i){
        temp += "\t";
    }
    
    return temp;
}

vector<string> Solution::prettyJSON(string A) {
    vector<string> ans;
    
    int n = A.size();
    
    int indent = 0 ;
    
    string temp = "";
    for(int i = 0 ; i < n ; ++i){
        
        if(A[i] == '{' or A[i] == '['){
            string indentString = doIndent(indent);
            if((int)temp.size() > 0 ){
                // cout << temp <<" ";
                ans.push_back(indentString + temp);
            }
            temp = "";
            indentString += A[i];
            ans.push_back(indentString);
            indent++;
        }
        else if(A[i] == '}' or A[i] == ']'){
            if((int)temp.size()){
                string indentString = doIndent(indent);
                ans.push_back(indentString + temp);
            }
            // else{
                --indent;
            // }
            
            
            string indentString = doIndent(indent);
            temp = "";
            if(i+1 < n && A[i+1] == ','){
                indentString += A[i];
                indentString += A[i+1];
                ++i;
            }
            else
                indentString += A[i];
            ans.push_back(indentString);
            
        }
        else if(A[i] == ','){
            
            string indentString = doIndent(indent);
            temp += A[i];
            if(temp.size()){
                ans.push_back(indentString + temp);
            }
            // cout << "yes";
            temp = "";
        }
        else{
            temp += A[i];
        }
    }
 
    
    return ans;
}
