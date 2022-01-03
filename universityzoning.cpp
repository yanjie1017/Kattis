#include <iostream> 
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
struct student {
    ll id;
    ll faculty_id;
    pair<ll, ll> pos;
    pair<ll, ll> assigned_cell;
    ll step = 0;
};

struct faculty {
    ll id;
    ll num_of_cell;
    ll target;
    vector <pair<ll, ll>> coord_of_cell;
    vector <student*> enrolled_student;
    ll total_step_required = 0;
};

int main(){
    //freopen("sample5.in","r",stdin);
    ll R, C, F, S, G;
    cin >> R >> C >> F >> S >> G;
    
    // input: faculty
    vector<faculty*> FACULTIES;
    for (ll i=1; i<=F; i++){
        faculty* f = new faculty();
        f->id = i;
        cin >> (f->num_of_cell);
        for (ll j=0; j<(f->num_of_cell); j++){
            pair<ll, ll> coord;
            cin >> coord.first >> coord.second;
            f->coord_of_cell.push_back(coord);
        }
        std::sort(f->coord_of_cell.begin(),f->coord_of_cell.end());
        FACULTIES.push_back(f);
    }

    // input: student
    for (ll i=0; i<S; i++){
        student* s = new student();
        cin >> s->pos.first >> s->pos.second >> s->id >> s->faculty_id;
        FACULTIES[s->faculty_id-1]->enrolled_student.push_back(s);
    }    

    // input: target
    for (auto& f:FACULTIES){
        cin >> f->target;
    } 

    // main
    ll g = 0;
    for (auto& fac:FACULTIES){
        std::sort(fac->enrolled_student.begin(), fac->enrolled_student.end(), 
        [] (const student* a, const student* b){
            return a->id < b->id;                           // sort student by id
        });                                             
        // check if students in assigned cell
        ll idx = 0;
        for (auto& stu:fac->enrolled_student){  
            stu->assigned_cell = fac->coord_of_cell[idx++];          
            if (stu->assigned_cell == stu->pos){            // if coord == pos, then target --
                fac->target -= 1;
            } else {                                        // if coord != pos, then count step
                stu->step = (std::abs(stu->assigned_cell.first - stu->pos.first)
                                + std::abs(stu->assigned_cell.second - stu->pos.second));
            }
        }
        // calculate steps required to meet target
        if (fac->target > 0) {
            std::sort(fac->enrolled_student.begin(), fac->enrolled_student.end(), 
            [] (const student* a, const student* b){
                return a->step < b->step;                   // sort student by step
            });                                         
            for (auto& stu:fac->enrolled_student){
                if (stu->step == 0) continue;               // skip student who is in assigned cell
                fac->total_step_required += stu->step;  
                fac->target -= 1;
                if (fac->target == 0) break;                // if meet target, then break
            }
        } else {
            g++;
        }
        if (g >= G){                                        // if meet compliance, then return value
            cout << 0 << "\n"; 
            return 0;
        }   
    }
    // calculate steps required to meet compliance
    ll total_step = 0;
    std::sort(FACULTIES.begin(), FACULTIES.end(), 
    [] (const faculty* a, const faculty* b){
        return a->total_step_required < b->total_step_required; // sort faculties by steps required
    });     
    for (const auto& fac:FACULTIES){                                
        if (fac->total_step_required == 0) continue;        // skip faculty that meets target
        total_step += fac->total_step_required;   
        g++;    
        if (g == G){                                        // if meet compliance, then return value
            cout << total_step << "\n"; 
            return 0;
        }    
    }
    /*// debug
    for (const auto& fac:FACULTIES){
        cout << fac->id << " " << fac->num_of_cell << " " << fac->target << " " << fac->total_step_required << "\n";
        for (const auto& cell:fac->coord_of_cell){
            cout << cell.first << " " << cell.second << "\n";
        }
        for (const auto& stu:fac->enrolled_student){
            cout << stu->id << " " << stu->pos.first << " " << stu->pos.second << " " 
            << stu->assigned_cell.first << " " << stu->assigned_cell.second << " " << stu->step << "\n";
        }
    }
    */
}