#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ifstream Fin; 
    ofstream Fop;
    
  //Task 1 -------------------------------------------------------------------------------

    Fin.open("INPUT\\main.csv");
    Fop.open("OUTPUT\\filteredCountry.csv");

    string sku, desc, year, cap, url, price, seller_info, offer_desc, country;
    
    Fop<<"SKU,DESCRIPTION,YEAR,CAPACITY,URL,PRICE,SELLER_INFORMATION,OFFER_DESCRIPTION,COUNTRY\n";

    while(Fin.good()){
        getline(Fin,sku,',');
        getline(Fin,desc,',');
        getline(Fin,year,',');
        getline(Fin,cap,',');
        getline(Fin,url,',');
        getline(Fin,price,',');
        getline(Fin,seller_info,',');
        getline(Fin,offer_desc,',');
        getline(Fin,country,'\n');
        
       if(country.substr(0,3)=="USA") 
          Fop<<sku<<","<<desc<<","<<year<<","<<cap<<","<<url<<","<<price.substr(1)<<","<<seller_info<<","<<offer_desc<<","<<country<<"\n"; 
    }
        Fin.close();
        Fop.close();

   //Task 2 -------------------------------------------------------------------------------     
        Fin.open("OUTPUT\\filteredCountry.csv");
        Fop.open("OUTPUT\\lowestPrice.csv");
        
        //column names
        Fop<<"SKU,FIRST_MINIMUM_PRICE,SECOND_MINIMUM_PRICE\n";

        // map to group SKU with an array of prices.
     map <string , vector <float> > Map; 
    
     while(Fin.good()){
        getline(Fin,sku,',');
        getline(Fin,desc,',');
        getline(Fin,year,',');
        getline(Fin,cap,',');
        getline(Fin,url,',');
        getline(Fin,price,',');
        getline(Fin,seller_info,',');
        getline(Fin,offer_desc,',');
        getline(Fin,country,'\n');
        
        float p = 0;
        float frac=0;
        int i,count=0;
        for(i=0 ; price[i] && price[i]!='.' ; i++) p = p*10 + price[i]-'0';
        if(price[i]){
           i++;
           while(price[i++]){
               frac = frac*10 + price[i]%10; 
               count++; 
           } 
        }

        if(sku.substr(0,3)!="SKU"){
            p += frac/(1.0*pow(10,count));
            Map[sku].push_back(p);     
        }
    }   

     //Traversing the map to find the first and second minimum price for each sku
          
       for(auto i:Map){
           
           vector <float> v = i.second;
           sort(v.begin(),v.end());
          
          if(i.first.length()>0){
            if(v.size()==1)  
               Fop<<i.first<<","<<v[0]<<","<<"NA\n";   //if only one price variety exists
            else   
               Fop<<i.first<<","<<v[0]<<","<<v[1]<<"\n";
          } 
             
       } 
            Fin.close();
            Fop.close();
}