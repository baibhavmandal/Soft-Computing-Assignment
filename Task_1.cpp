#include <iostream>
#include <vector>

using namespace std;

vector<pair<float, float>> Cartesian(vector<float> a, vector<float> b, int n) {
    vector<pair<float, float>> ans;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            ans.push_back({a[i], b[j]});
        }
    }
    return ans;
}

vector<float> Complement(vector<float> a, int n) {
    vector<float> ans;

    for(int i = 0; i < n; ++i) {
        float ans_ = 1 - a[i];
        ans.push_back(ans_);
    }

    return ans;
}

vector<float> Intersection(vector<float> a, vector<float> b, int n) {
    vector<float> ans;

    for(int i = 0; i < n; ++i) {
        ans.push_back(min(a[i], b[i]));
    }

    return ans;
}

vector<float> Union(vector<float> a, vector<float> b, int n) {
    vector<float> ans;

    for(int i = 0; i < n; ++i) {
        ans.push_back(max(a[i], b[i]));
    }

    return ans;
}

// main function
int main() {
    std::cout << "Welcome!! This is my Soft Computing Assignment \n";

    // Task 1 -> Implementation of Fuzzy Operation
    vector<float> A, B; // for custom set values
    A = {0.5, 0.075, 0.08, 0.025};
    B = {0.25, 0.1, 0.02, 0.125};

    cout << "Enter capacity or size of set A and B: \n";
    int n = 4;

    // for custom inputs
    int choice;

    do {
        cout << "Enter 0 for pre-loaded inputs \n";
        cout << "Enter 1 for custom inputs \n";
        cin >> choice;
        if(choice == 0) {
            break;
        }
        else if(choice == 1) {
            cout << "Enter capacity or size of set A and B: \n";
            cin >> n; // capacity of set A and B

            A = {};
            B = {};

            cout << "Enter" <<  n << "values of set A: \n";

            for (int i = 0; i < n; ++i) {
                float input;
                cin >> input;
                A.push_back(input);
            }

            cout << "Enter" <<  n  << "values of set B: \n";

            for (int i = 0; i < n; ++i) {
                float input;
                cin >> input;
                B.push_back(input);
            }
        }
        else {
            cout << "Select Correct option \n";
        }
    }
    while(choice != 0 && choice != 1);

    cout << "Values of set A are: \n";

    for(int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }

    cout << "\n";

    cout << "Values of set B are: \n";

    for(int i = 0; i < n; ++i) {
        cout << B[i] << " ";
    }

    cout << "\n";
    // 1. Union, 2. Intersection, 3. Complement and Difference operations on fuzzy sets.
    // 1. Union

    vector<float> union_ = Union(A, B, n);

    cout << "Union of set A and B: \n";

    for(int i = 0; i < n; ++i) {
        cout << union_[i] << " ";
    }

    cout << "\n";

    // 2. Intersection

    vector<float> intersec_ = Intersection(A, B, n);

    cout << "Intersection of set A and B: \n";

    for(int i = 0; i < n; ++i) {
        cout << intersec_[i] << " ";
    }

    cout << "\n";

    // 3. Complement

    vector<float> Complement_A = Complement(A, n);

    cout << "Complement of set A: \n";

    for(int i = 0; i < n; ++i) {
        cout << Complement_A[i] << " ";
    }

    cout << "\n";

    vector<float> Complement_B = Complement(B, n);

    cout << "Complement of set B: \n";

    for(int i = 0; i < n; ++i) {
        cout << Complement_B[i] << " ";
    }

    cout << "\n";

    // 4. Difference

    vector<float> Difference_AB = Intersection(A, Complement_B, n);

    cout << "Difference of A | B: \n";

    for(int i = 0; i < n; ++i) {
        cout << Difference_AB[i] << " ";
    }

    cout << "\n";

    vector<float> Difference_BA = Intersection(Complement_A, B, n);

    cout << "Difference of B | A: \n";

    for(int i = 0; i < n; ++i) {
        cout << Difference_BA[i] << " ";
    }

    cout << "\n";

    // 5. Cartesian Product

    vector<pair<float, float>> Cartesian_AB = Cartesian(A, B, n);
    vector<pair<float, float>> Cartesian_BA = Cartesian(B, A, n);

    cout << "Cartesian Product of A and B: \n";

    for(int i = 0; i < Cartesian_AB.size(); ++i) {
        cout << "(" << Cartesian_AB[i].first << "," << Cartesian_AB[i].second << ")\n";
    }

    cout << "Cartesian Product of B and A: \n";

    for(int i = 0; i < Cartesian_BA.size(); ++i) {
        cout << "(" << Cartesian_BA[i].first << "," << Cartesian_BA[i].second << ")\n";
    }

    return 0;
}
