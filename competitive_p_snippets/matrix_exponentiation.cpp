struct Matrix{
    vector< vector<int> > mat;
    int row, col;

    Matrix(int r, int c) {
        mat.resize(r);
        for(int i=0;i<r;i++) {
            mat[i].resize(c,0);
        }
        row = r;
        col = c;
    }

    Matrix(vector <vector<int>> values): mat(values), row(values.size()), col(values[0].size()) {}

    static Matrix identity_matrix(int n) {
        vector< vector<int> > values(n, vector<int>(n,0));
        for(int i=0;i<n;i++) {
            values[i][i] = 1;
        }
        return values;
    }

    Matrix operator *(const Matrix &other) {
        assert(col == other.row);
        vector <vector<int> > result(row, vector<int>(other.col,0));
        for(int i=0;i<row;i++) {
            for(int j=0;j<other.col;j++) {
                for(int k=0;k<col;k++) {
                    result[i][j] = (result[i][j] + mat[i][k] * 1LL * other.mat[k][j])%MOD; //apply MOD if needed
                }
            }
        }
        return Matrix(result);
    }

    void print() {
        cout << "Printing Matrix " << endl;
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

Matrix power(Matrix m, int power) {
    assert(m.row == m.col);
    Matrix result = Matrix::identity_matrix(m.row);
    while(power) {
        if(power&1) result = result * m;
        m = m*m;
        power>>=1;
    }
    return result;
}