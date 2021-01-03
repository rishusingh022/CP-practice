for(j=player.begin(),i=ranked.begin();j!=player.end()||i!=ranked.end();j++,i++){
        //if first element is smallest in both 
        //*j==*min_element(player.begin(),player.end()) &&
        if(*j<*min_element(ranked.begin(),ranked.end())){
            ranked.push_back(*j);
            int b=*j;
            vector<int> temp=ranked;
            vector<int>::iterator ip; 
            ip = unique(temp.begin(),temp.end());
            temp.resize(distance(temp.begin(), ip)); 
            ip=find(temp.begin(), temp.end(),b);
            result.push_back(ip-temp.begin()+1);
            //result.push_back(distance(ranked.begin(),ranked.end()));
        }
        else{
            if(*j>=*i){
                ranked.insert(i,*j);
                int b=*j;
                vector<int> temp=ranked;
                vector<int>::iterator ip; 
                ip = unique(temp.begin(),temp.end());
                temp.resize(distance(temp.begin(), ip)); 
                ip=find(temp.begin(), temp.end(),b); 
                result.push_back(ip-temp.begin()+1);
                //player.erase(j);
                break;
            }
        }
        
    }