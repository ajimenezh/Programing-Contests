#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

string countries[] = {"Afghanistan","Akrotiri","Albania","Algeria","American Samoa","Andorra","Angola","Anguilla","Antarctica","Antigua and Barbuda","Argentina","Armenia","Aruba","Ashmore and Cartier Islands","Australia","Austria","Azerbaijan","Bahamas, The","Bahrain","Bangladesh","Barbados","Bassas da India","Belarus","Belgium","Belize","Benin","Bermuda","Bhutan","Bolivia","Bosnia and Herzegovina","Botswana","Bouvet Island","Brazil","British Indian Ocean Territory","British Virgin Islands","Brunei","Bulgaria","Burkina Faso","Burma","Burundi","Cambodia","Cameroon","Canada","Cape Verde","Cayman Islands","Central African Republic","Chad","Chile","China","Christmas Island","Clipperton Island","Cocos (Keeling) Islands","Colombia","Comoros","Congo, Democratic Republic of the","Congo, Republic of the","Cook Islands","Coral Sea Islands","Costa Rica","Cote d'Ivoire","Croatia","Cuba","Cyprus","Czech Republic","Denmark","Dhekelia","Djibouti","Dominica","Dominican Republic","Ecuador","Egypt","El Salvador","Equatorial Guinea","Eritrea","Estonia","Ethiopia","Europa Island","Falkland Islands (Islas Malvinas)","Faroe Islands","Fiji","Finland","France","French Guiana","French Polynesia","French Southern and Antarctic Lands","Gabon","Gambia, The","Gaza Strip","Georgia","Germany","Ghana","Gibraltar","Glorioso Islands","Greece","Greenland","Grenada","Guadeloupe","Guam","Guatemala","Guernsey","Guinea","Guinea-Bissau","Guyana","Haiti","Heard Island and McDonald Islands","Holy See (Vatican City)","Honduras","Hong Kong","Hungary","Iceland","India","Indonesia","Iran","Iraq","Ireland","Isle of Man","Israel","Italy","Jamaica","Jan Mayen","Japan","Jersey","Jordan","Juan de Nova Island","Kazakhstan","Kenya","Kiribati","Korea, North","Korea, South","Kuwait","Kyrgyzstan","Laos","Latvia","Lebanon","Lesotho","Liberia","Libya","Liechtenstein","Lithuania","Luxembourg","Macau","Macedonia","Madagascar","Malawi","Malaysia","Maldives","Mali","Malta","Marshall Islands","Martinique","Mauritania","Mauritius","Mayotte","Mexico","Micronesia, Federated States of","Moldova","Monaco","Mongolia","Montserrat","Morocco","Mozambique","Namibia","Nauru","Navassa Island","Nepal","Netherlands","Netherlands Antilles","New Caledonia","New Zealand","Nicaragua","Niger","Nigeria","Niue","Norfolk Island","Northern Mariana Islands","Norway","Oman","Pakistan","Palau","Panama","Papua New Guinea","Paracel Islands","Paraguay","Peru","Philippines","Pitcairn Islands","Poland","Portugal","Puerto Rico","Qatar","Reunion","Romania","Russia","Rwanda","Saint Helena","Saint Kitts and Nevis","Saint Lucia","Saint Pierre and Miquelon","Saint Vincent and the Grenadines","Samoa","San Marino","Sao Tome and Principe","Saudi Arabia","Senegal","Serbia and Montenegro","Seychelles","Sierra Leone","Singapore","Slovakia","Slovenia","Solomon Islands","Somalia","South Africa","South Georgia and the South Sandwich Islands","Spain","Spratly Islands","Sri Lanka","Sudan","Suriname","Svalbard","Swaziland","Sweden","Switzerland","Syria","Taiwan","Tajikistan","Tanzania","Thailand","Timor-Leste","Togo","Tokelau","Tonga","Trinidad and Tobago","Tromelin Island","Tunisia","Turkey","Turkmenistan","Turks and Caicos Islands","Tuvalu","Uganda","Ukraine","United Arab Emirates","United Kingdom","United States","Uruguay","Uzbekistan","Vanuatu","Venezuela","Vietnam","Virgin Islands","Wake Island","Wallis and Futuna","West Bank","Western Sahara","Yemen","Zambia","Zimbabwe",""};
string cities1[] = {"Shanghai","Istanbul","Karachi","Mumbai","Moscow","São Paulo","Sao Paulo","Beijing","Guangzhou","Delhi","Shenzhen","Seoul","Jakarta","Tianjin","Tokyo","Cairo","Dhaka","Mexico City","Kinshasa","Bangalore","New York City","New York","London","Bangkok","Tehran","Dongguan","Lagos","Ho Chi Minh City","Bogotá","Lima","Hong Kong","Hanoi","Hyderabad","Xi'an","Wuhan","Rio de Janeiro","Lahore","Foshan","Ahmedabad","Baghdad","Shantou","Riyadh","Singapore","Jeddah","Santiago","Saint Petersburg","Chengdu","Chennai","Alexandria","Ankara","Chongqing","Kolkata","Surat","Johannesburg","Nanjing","Dar es Salaam","Yangon","Harbin","Zhengzhou","Suzhou","New Taipei City","Taipei","New Taipei","Sydney","Los Angeles","Shenyang","Melbourne","Yokohama","Abidjan","Busan","Hangzhou","Quanzhou","Berlin","Cape Town","Durban","Casablanca","Algiers","Nairobi","Hefei","Kabul","Pyongyang","Madrid","Ekurhuleni","Pune","Addis Ababa","Changsha","Jaipur","Xuzhou","Wenzhou", ""};
string cities2[] = {"Bangkok","Beijing","Bogotá","Buenos Aires","Cairo","Delhi","Dhaka","Guangzhou","Istanbul","Jakarta","Karachi","Kinshasa","Kolkata","Lagos","London","Manila","Mexico","Moscow","Mumbai","Osaka","Seoul","Shanghai","Tianjin","Tokyo", ""};
string cities3[] = {"Tokyo","Yokohama","Jakarta","Seoul","Incheon","Delhi","Shanghai","Manila","Karachi","Beijing","Guangzhou","Foshan","Mumbai","Osaka","Kobe","Kyoto","Moscow","Greater Cairo","Kolkata","Bangkok","Dhaka","Tehran","Istanbul","Shenzhen","Lagos","Paris","Nagoya","London","Lima","Kinshasa","Tianjin","Chennai","Chicago","Bengaluru","Bogotá","Ho Chi Minh City","Ho Chi Minh","Dongguan","Chengdu","Taipei","Hyderabad","Lahore","Johannesburg","East Rand","Wuhan","Essen","Düsseldorf","Ahmedabad","Chongqing","Kuala Lumpur","Hangzhou","Baghdad","Toronto","Santiago","Madrid","Dallas","Fort Worth","San Francisco","San Jose","Quanzhou","Miami","Nanjing","Shenyang","Belo Horizonte","Philadelphia","Houston","Luanda","Xi'an","Singapore","Pune","Milan","Riyadh","Khartoum","Washington","Washington, D.C.","Surat","Bandung","Atlanta","Surabaya","Yangon","Barcelona","Alexandria","Abidjan","Guadalajara","Harbin","Boston","Nairobi","Qingdao","Suzhou","Ankara","Monterrey","Zhengzhou","Salvador","Phoenix","Porto Alegre","Sydney","Berlin","Accra","Kuwait City","Kuwait","Rome","Recife","Dalian","Melbourne","Detroit","Medellín","Naples","Fortaleza","Kano","Fuzhou","Taiyuan","Hefei","Athens","Jinan","Kabul","Durban","Montreal","Wuxi","Tel","Kunming","Jeddah","Xiamen","Busan","Dubai","Ningbo","Caracas","Dakar","Aleppo","Curitiba","Changsha","Addis","Changchun","Jaipur","Faisalabad","Ibadan","Seattle","Rawalpindi","Islamabad","Casablanca","Mashhad","Chittagong","San Diego","Pyongyang","Shijiazhuang","Kanpur","Kumasi","Lucknow","Algiers","Taichung","Changzhou","İzmir","Ürümqi","Hyderabad","Wenzhou","Kiev","Kaohsiung","Kalyan","Guiyang","Damascus","Minneapolis","Saint Paul","Lisbon","Maputo","Sapporo","Amman","Douala","Sana'a","Nagpur","Pretoria","Yaoundé","Fukuoka","Campinas","Hanoi","Tampa","Lanzhou","Katowice","Gliwice–Tychy","Denver","Cali","Nanchang","Cebu City","Tunis","Daegu","Brasília","Guayaquil","Puebla","Shantou","Abuja","Maracaibo","Port-au-Prince","Tashkent","Zhangjiagang","Jiangyin","Frankfurt","Isfahan","Birmingham","Nanning","Zhongshan","Indore","Santo","Baltimore","Medan","Coimbatore","Manchester","Kochi","Asunción","Chaoyang","Chaonan","Ouagadougou","Bamako","Panama","Colombo","Vancouver","San","St. Louis","Patna","Goiânia","Linyi","Kozhikode","Rotterdam","The Hague","Belém","Baku","Havana","Shaoxing","Antananarivo","Cologne–Bonn","Baotou","Tangshan","Beirut","Kitakyūshū","Port","Hohhot","Bhopal","Las Vegas","Brussels","Barranquilla","Bucharest","Orlando","Manaus","Portland","Brisbane","Vadodara","Valencia","Rabat","Multan","Lomé","Gujranwala","Minsk","San Antonio","Huai'an","Thrissur","Lusaka","Semarang","Conakry","Tijuana","Agra","Kampala","Visakhapatnam","Hamburg","Sacramento","La Paz","Cleveland","Thiruvananthapuram","Luoyang","Santa","Toluca","Pittsburgh","Vienna","Bursa","Handan","Budapest","Santos","Warsaw","Shiraz","Malappuram","Lubumbashi","Yinchuan","Phnom","Brazzaville","Ludhiana","Quito","Vitória","León","Montevideo","Perth","Tabriz","Santa Cruz de la Sierra","San Salvador","Kannur","Jilin","Johor","Mogadishu","Nashik","Cincinnati","Harare","Datong","Kaduna","Peshawar","Haikou","Makassar","Zibo","Kunshan","Yangzhou","Marseille","Anshan","Mosul","Mecca","Córdoba","Vijayawada","Lyon","Kansas","Kansas City","San","Leeds","Bradford","Palembang","Indianapolis","Madurai","Daejeon","Turin","Varanasi","Davao","Meerut","Austin","Gwangju","Adana","Novosibirsk","Virginia","Liuzhou","Rajkot","Kharkiv","Benin","Stockholm","Mbuji","Mayi","Weifang","Almaty","Fushun","Columbus","Porto","Jamshedpur","Milwaukee","Huizhou","Yantai","Ciudad","Munich","Natal","Yekaterinburg","Sendai","Srinagar","Jabalpur","Hiroshima","Virginia Beach","Norfolk","Baoding","Auckland","Charlotte","Yerevan","Asansol","Rosario","Zhuhai","Stuttgart","Allahabad","Barquisimeto","Prague","Torreón","Tainan","Yogyakarta","Dhanbad","Nizhny","Xuzhou","Aurangabad","Ahvaz","Amritsar","Guatemala","Maceió","Copenhagen","Wuhu","Qiqihar","Gaziantep","Glasgow","Cixi","Xining","Zhangzhou","Niamey","João","Anyang","Jodhpur","Providence","Sofia","Khulna","Ranchi","Raipur","Huambo","Medina","Durg","Bhilai","Samara","Tripoli","Helsinki","Gwalior","Putian","Penang","Omsk","Vasai","Virar","Querétaro","Dublin","Zhangjiakou","Kazan","Changshu","Bucaramanga","Maracay","Tegucigalpa","Chelyabinsk","Tbilisi","Adelaide","Calgary","Fes","Huainan","Kollam","Mandalay","Kathmandu","Naypyidaw","Belgrade","Jacksonville","Xiangyang","Joinville","Ulan","Rostov","on","Don","Ulsan","Chifeng","Jiamusi","Memphis","Erbil","Chandigarh","Haifa","Konya","Tiruchirappalli","Salt","Florianópolis","Dongying","Mombasa","Mérida","Kigali","Lille","Amsterdam","Xinxiang","Kota","Jiaxing","Zaria","N'Djamena","San","Huaibei","Nantong","Qom","Mysore","Bareilly","Nuremberg","Ufa","Guwahati","Nashville","Odessa","Cartagena","Hamamatsu","Monrovia","Port","Changwon","Dnipropetrovsk","Mbuji","Mayi","Nizhny Novgorod","Guatemala City","João Pessoa","Durg","Bhilai","Vasai","Virar", ""};
string cities[6][500] = {
{"Mumbai","Delhi","Bangalore","Hyderabad","Ahmedabad","Chennai","Kolkata","Surat","Pune","Jaipur","Lucknow","Kanpur","Nagpur","Indore","Thane","Bhopal","Visakhapatnam","Pimpri-Chinchwad","Patna","Vadodara","Ghaziabad","Ludhiana","Agra","Nashik","Faridabad","Meerut","Rajkot","Kalyan-Dombivali","Vasai-Virar","Solapur","Varanasi","Srinagar","Aurangabad","Dhanbad","Amritsar","Navi","Allahabad","Ranchi","Howrah","Coimbatore","Jabalpur","Gwalior","Vijayawada","Jodhpur","Madurai","Raipur","Kota","Guwahati","Chandigarh","Hubballi-Dharwad","Bareilly","Moradabad","Mysore","Gurgaon","Aligarh","Jalandhar","Tiruchirappalli","Bhubaneswar","Salem","Mira-Bhayandar","Trivandrum","Bhiwandi","Saharanpur","Gorakhpur","Guntur","Bikaner","Amravati","Noida","Jamshedpur","Bhilai","Warangal","Mangalore","Cuttack","Firozabad","Kochi","Bhavnagar","Dehradun","Durgapur","Asansol","Nanded","Kolhapur","Ajmer","Gulbarga","Jamnagar","Ujjain","Loni","Siliguri","Jhansi","Ulhasnagar","Nellore","Jammu","Sangli-Miraj","Belgaum","Ambattur","Tirunelveli","Malegaon","Gaya","Jalgaon","Udaipur","Maheshtala","Tirupur","Davanagere","Kozhikode","Akola","Kurnool","Rajpur","Bokaro","South","Bellary","Patiala","Gopalpur","Agartala","Bhagalpur","Muzaffarnagar","Bhatpara","Panihati","Latur","Dhule","Rohtak","Korba","Bhilwara","Brahmapur","Muzaffarpur","Ahmednagar","Mathura","Kollam","Avadi","Rajahmundry","Kadapa","Kamarhati","Bilaspur","Shahjahanpur","Bijapur","Rampur","Shivamogga","Chandrapur","Junagadh","Thrissur","Alwar","Bardhaman","Kulti","Kakinada","Nizamabad","Parbhani","Tumkur","Hisar","Ozhukarai","Bihar","Panipat","Darbhanga","Bally","Aizawl","Dewas","Ichalkaranji","Tirupati","Karnal","Bathinda","Jalna","Gujarat","Barasat","Kirari","Purnia","Satna","Mau","Sonipat","Farrukhabad","Sagar","Rourkela","Durg","Imphal","Ratlam","Hapur","Anantapur","Arrah","Karimnagar","Etawah","Ambernath","North","Bharatpur","Begusarai","New","Gandhidham","Baranagar","Tiruvottiyur","Puducherry","Sikar","Thoothukudi","Rewa","Mirzapur","Raichur","Pali","Ramagundam","Vizianagaram","Katihar","Haridwar","Sri","Karawal","Nagercoil","Mango","Bulandshahr","Thanjavur",""},
{"Chicago","Houston","Philadelphia","Phoenix","San Jose","Dallas","Austin","Jacksonville","Indianapolis","San Francisco","Columbus","Fort","Charlotte","Detroit","El Paso","Memphis","Boston","Seattle","Colorado Springs","Oklahoma City","Denver","Washington","Nashville","Baltimore","Louisville","Portland","Oklahoma","Milwaukee","Fort Wayne","Chula Vista","Saint Paul","New Orleans","Jersey City","Corpus Christi","Las","Albuquerque","Tucson","Fresno","Sacramento","Long","Kansas","Mesa","Virginia","Atlanta","Colorado","Raleigh","Omaha","Miami","Oakland","Tulsa","Minneapolis","Cleveland","Wichita","Arlington","New","Bakersfield","Tampa","Honolulu","Anaheim","Aurora","Santa","St.","Riverside","Corpus","Pittsburgh","Lexington","Anchorage","Stockton","Cincinnati","Saint","Toledo","Newark","Greensboro","Plano","Henderson","Lincoln","Buffalo","Fort","Jersey","Chula","Orlando","St.","Norfolk","Chandler","Laredo","Madison","Durham","Lubbock","Winston–Salem","Garland","Glendale","Hialeah","Reno","Baton","Irvine","Chesapeake","Irving","Scottsdale","North","Fremont","Gilbert","San","Boise","Birmingham","Rochester","Richmond","Spokane","Des","Montgomery","Modesto","Fayetteville","Tacoma","Shreveport","Fontana","Oxnard","Aurora","Moreno","Akron","Yonkers","Columbus","Augusta","Little","Amarillo","Mobile","Huntington","Glendale","Grand","Salt","Tallahassee","Huntsville","Worcester","Knoxville","Grand","Newport","Brownsville","Santa","Overland","Providence","Jackson","Garden","Oceanside","Chattanooga","Fort","Rancho","Santa","Port","Ontario","Tempe","Vancouver","Springfield","Cape","Pembroke","Sioux","Peoria","Lancaster","Elk","Corona","Eugene","Salem","Palmdale","Salinas","Springfield","Pasadena","Rockford","Pomona","Hayward","Fort","Joliet","Escondido","Kansas","Torrance","Bridgeport","Alexandria","Sunnyvale","Cary","Lakewood","Hollywood","Paterson","Syracuse","Naperville","McKinney","Mesquite","Clarksville","Savannah","Dayton","Orange","Fullerton","Pasadena","Hampton","McAllen","Killeen","Warren","West","Columbia","New","Sterling","Olathe","Miramar","Thousand","Frisco","Cedar","Topeka","Visalia","Waco","Elizabeth","Bellevue","Gainesville","Simi","Charleston","Carrollton","Coral","Stamford","Hartford","Concord","Roseville","Thornton","Kent","Lafayette","Surprise","Denton","Victorville","Evansville","Midland","Santa","Athens","Allentown","Abilene","Beaumont","Vallejo","Independence","Springfield","Ann","Provo","Peoria","Norman","Berkeley","El","Murfreesboro","Lansing","Columbia","Downey","Costa","Inglewood","Miami","Manchester","Elgin","Wilmington","Waterbury","Fargo","Arvada","Carlsbad","Westminster","Rochester","Gresham","Clearwater","Lowell","West","Pueblo","San","Fairfield","West","Billings","Murrieta","High","Round","Richmond","Cambridge","Norwalk","Odessa","Antioch","Temecula","Green","Everett","Wichita","Burbank","Palm","Centennial","Daly","Richardson","Pompano","Broken","North","",""},
{"Bath","Birmingham","Bradford","Brighton","Bristol","Cambridge","Canterbury","Carlisle","Chelmsford","Chester","Chichester","Coventry","Derby","Durham","Ely","Exeter","Gloucester","Hereford","Kingston","Lancaster","Leeds","Leicester","Lichfield","Lincoln","Liverpool","City","Manchester","Newcastle","Norwich","Nottingham","Oxford","Peterborough","Plymouth","Portsmouth","Preston","Ripon","Salford","Salisbury","Salisbury","Sheffield","Southampton","St Albans","Stoke-on-Trent","Sunderland","Truro","Wakefield","Wells","City","Winchester","Wolverhampton","Worcester","York",""},
{"Amsterdam","Antwerp","Athens","Barcelona","Belgrade","Berlin","Bremen","Greater","Brussels-Capital","Bucharest","Budapest","Cardiff","Copenhagen","Donetsk","Dnipropetrovsk","Dublin","Frankfurt/Rhine-Main","Greater Bristol","Hamburg","Helsinki","Istanbul","Katowice","Kazan","Kharkiv","Kiev","Kraków","West","Lille-Kortrijk-Tournai","Lisbon","Liverpool","Łódź","London","Lyon","Madrid","The Hague","Greater","Marseille","Milan","Minsk","Moscow","Munich","Naples","Nice","Nizhniy","Nottingham-Derby","Nuremberg","Odessa","Greater","Paris","Perm","Greater","Portsmouth-Southampton","Prague","Rhein-Nord","Rhein-Süd","Riga","Rome","Rostov-on-Don","Rotterdam","Ruhr","Saarbrücken","Saint","Samara","Saratov","Seville","Sofia","Metropolitan","South","Stuttgart","Thessaloniki","Turin","Newcastle-Sunderland","Ufa","Valencia","Vienna","Volgograd","Warsaw","West","Zagreb","Zürich","",""},
{"Abu Dhabi","Abuja","Accra","Adamstown","Addis Ababa","Algiers","Alofi","Amman","Amsterdam","Andorra","Ankara","Antananarivo","Apia","Ashgabat","Asmara","Astana","Asunción","Athens","Avarua","Baghdad","Baku","Bamako","Bandar","Bangkok","Bangui","Banjul","Basseterre","Beijing","Beirut","Belgrade","Belmopan","Berlin","Bern","Bishkek","Bissau","Bogotá","Brasília","Bratislava","Brazzaville","Bridgetown","Brussels","Bucharest","Budapest","Buenos","Bujumbura","Cairo","Canberra","Caracas","Castries","Cayenne","Charlotte","Chisinau","Cockburn","Conakry","Copenhagen","Dakar","Damascus","Dhaka","Dili","Djibouti","Dodoma","Dar","Doha","Douglas","Dublin","Dushanbe","Edinburgh","El","Episkopi","Flying","Freetown","Funafuti","Gaborone","George","Georgetown","Georgetown","Gibraltar","Grytviken","Guatemala","Gustavia","Hagåtña","Hamilton","Hanga","Hanoi","Harare","Hargeisa","Havana","Helsinki","Honiara","Islamabad","Jakarta","Jamestown","Jerusalem","Jerusalem","Ramallah","Juba","Kabul","Kampala","Kathmandu","Khartoum","Kiev","Kigali","Kingston","Kingston","Kingstown","Kinshasa","Kuala","Putrajaya","Kuwait","Libreville","Lilongwe","Lima","Lisbon","Ljubljana","Lomé","London","Luanda","Lusaka","Luxembourg","Madrid","Majuro","Malabo","Malé","Managua","Manama","Manila","Maputo","Marigot","Maseru","Mata-Utu","Mbabane","Lobamba","Melekeok","Ngerulmud","Mexico","Minsk","Mogadishu","Monaco","Monrovia","Montevideo","Moroni","Moscow","Muscat","Nairobi","Nassau","Naypyidaw","N'Djamena","New","Niamey","Nicosia","Nicosia","Nouakchott","Nouméa","Nukuʻalofa","Nuuk","Oranjestad","Oslo","Ottawa","Ouagadougou","Pago","Palikir","Panama","Papeete","Paramaribo","Paris","Philipsburg","Phnom","Plymouth","Brades","Podgorica","Cetinje","Port","Port","Port","Port-au-Prince","Port","Porto-Novo","Cotonou","Prague","Praia","Pretoria","Bloemfontein","Cape","Pristina","Pyongyang","Quito","Rabat","Reykjavík","Riga","Riyadh","Road","Rome","Roseau","Saipan","San","San","San","San","Sana'a","Santiago","Valparaíso","Santo","São","Sarajevo","Seoul","Singapore","Skopje","Sofia","Sri","Colombo","St.","St.","St.","St.","St.","Stanley","Stepanakert","Stockholm","Sucre","La","Sukhumi","Suva","Taipei","Tallinn","Tarawa","Tashkent","Tbilisi","Kutaisi","Tegucigalpa","Tehran","Thimphu","Tirana","Tiraspol","Tokyo","Tórshavn","Tripoli","Tskhinvali","Tunis","Ulan","Vaduz","Valletta","The","Vatican","Victoria","Vienna","Vientiane","Vilnius","Warsaw","Washington,","Wellington","West","Willemstad","Windhoek","Yamoussoukro","Abidjan","Yaoundé","Yaren","Yerevan","Zagreb","",""},
{"Everest","K2","Kangchenjunga","Lhotse","Makalu","Cho Oyu","Dhaulagiri","Manaslu","Nanga Parbat","Annapurna","Gasherbrum I","Broad Peak","Gasherbrum II","Shishapangma","Gasherbrum",""}

};

set<string> places;
string text;

bool search(string s) {
    int last = 100000;
    int article = 10000;
    for (int i=0; i<text.size()-s.length(); i++) {
        if (text[i]!=' ' && (i==0 || text[i-1]==' ')) {
            if (text.substr(i,s.length())==s) {
                if (last<3) return true;
                if (article<2) return true;
            }
            if (text.substr(i,2)=="in" || text.substr(i,2)=="at") {
                last = 0;
            }
            if (text.substr(i,2)=="In" || text.substr(i,2)=="At") {
                last = 0;
            }
            if (text.substr(i,3)=="the" || text.substr(i,3)=="The") {
                article = 0;
            }
            last++;
            article++;
        }
        if (text[i]=='.' || text[i]==',') last = 1000;
        if (text[i]=='.' || text[i]==',') article = 1000;
    }
    return false;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    /*

    string s;


    cout<<"{";
    bool first = 0;
    while (getline(cin,s)) {
        if (first) cout<<",";
        cout<<"\""<<s<<"\"";
        first = 1;
    }

    cout<<",\"\"}";



    while (getline(cin,s)) {
        stringstream ss(s);
        ss>>s;
        ss>>s;
        for (int i=0; i<s.length(); i++) if (s[i]=='[') {
            s = s.substr(0,i);
            break;
        }
        cout<<s<<endl;
        getline(cin,s);
        getline(cin,s);
    }

    */

    for (int i=0; countries[i]!=""; i++) places.insert(countries[i]);
    for (int i=0; cities1[i]!=""; i++) places.insert(cities1[i]);
    for (int i=0; cities2[i]!=""; i++) places.insert(cities2[i]);
    for (int i=0; cities3[i]!=""; i++) places.insert(cities3[i]);
    for (int k=0; k<6; k++) {
        for (int i=0; cities[k][i]!=""; i++) places.insert(cities[k][i]);
    }

    getline(cin, text);

    int n;
    cin>>n;
    string s;
    getline(cin,s);

    for (int i=0; i<n; i++) {
        getline(cin,s);
        //if (s[0]>='a' && s[0]<='z') s[0] = char(s[0]-'a'+'A');
        if (places.find(s)!=places.end()) cout<<"place"<<endl;
        else {
            if (search(s)) cout<<"place"<<endl;
            else cout<<"person"<<endl;
        }
    }



    return 0;

}
