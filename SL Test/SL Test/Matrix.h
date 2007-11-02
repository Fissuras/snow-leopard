// Matrix.h: interface for the Matrix class.
//
//////////////////////////////////////////////////////////////////////

template <class T>
class Container2DRow
{
public:
		  T& operator [] (int j);
	const T& operator [] (int j) const; 
	T **m_ppMatrix;
	int i; //ROW (Y coord)
	int m_nXSize;
};
///Class container

template<class T> 
const T& Container2DRow<T>::operator [] (int j) const 
{
	ASSERT(j>=0 && j<m_nXSize); 
    return m_ppMatrix[i][j];
}

template<class T> 
T& Container2DRow<T>::operator [] (int j) 
{
	ASSERT(j>=0 && j<m_nXSize); 
    return m_ppMatrix[i][j];
}



template <class T>
class Matrix  
{
public:
	Container2DRow<T> row;

private:
	int m_nXSize;
	int m_nYSize;
	int m_nMemorySize;
	T **m_ppMatrix;

	bool m_bCreated;
public:
	//Constructor & Copy Constructor
	Matrix(int nYSize, int nXSize);
	Matrix(const Matrix& matrix);

	Matrix& operator= (const Matrix& matrix);
	Matrix  operator+ (const T& item);
	Matrix  operator- (const T& item);
	
	//Indexing //Y(row) X(col) 
	T& operator()(int i, int j);   // i - row
	    Container2DRow<T> operator [] (int i);
const	Container2DRow<T> operator [] (int i) const; 


	T SumAll();
	//Get Size
	int GetXSize();
	int GetYSize();
	T GetMinValue();
	T GetMaxValue();


	virtual ~Matrix();

};

template<class T>
Matrix<T>::Matrix(int nYSize, int nXSize)
{
	m_bCreated = false;
	ASSERT(nXSize>0 && nYSize>0);


	m_nXSize = nXSize;
	m_nYSize = nYSize;
	m_nMemorySize = m_nYSize*m_nXSize*sizeof(T);

	m_ppMatrix    = new T* [m_nYSize];
    m_ppMatrix[0] = new T  [m_nYSize*m_nXSize];

	for (int i=1; i<m_nYSize; i++)
		m_ppMatrix[i] = m_ppMatrix[0]+i*m_nXSize;
		
	memset(m_ppMatrix[0], 0, m_nMemorySize);
	m_bCreated = true;
	row.m_ppMatrix = m_ppMatrix;
	row.m_nXSize   = m_nXSize;
}

template<class T>
Matrix<T>::Matrix(const Matrix& matrix)
{
		m_nXSize = matrix.m_nXSize;
		m_nYSize = matrix.m_nYSize;
		m_nMemorySize = m_nYSize*m_nXSize*sizeof(T);

		m_ppMatrix    = new T* [m_nYSize];
		ASSERT(m_ppMatrix!=NULL);
        
		m_ppMatrix[0] = new T  [m_nYSize*m_nXSize];
		ASSERT(m_ppMatrix[0]!=NULL);

		for (int i=1; i<m_nYSize; i++)
			m_ppMatrix[i] = m_ppMatrix[0]+i*m_nXSize;

		memcpy(m_ppMatrix[0],matrix.m_ppMatrix[0], m_nMemorySize);

		m_bCreated = true;
}


template<class T>
Matrix<T>& Matrix<T>::operator= (const Matrix& matrix)
{
	if (this == &matrix) return *this;

	ASSERT(m_nXSize == matrix.m_nXSize && 
		   m_nYSize == matrix.m_nYSize);
	memcpy(m_ppMatrix[0],matrix.m_ppMatrix[0], m_nMemorySize);

	return *this;
}
template<class T>
T Matrix<T>::GetMinValue()
{
	T minValue = m_ppMatrix[0][0];
	int i,j;

		for (i=0; i<m_nYSize; i++)
		for (j=0; j<m_nXSize; j++)
		{
			if(m_ppMatrix[i][j]<minValue)
				minValue = m_ppMatrix[i][j];
		}
		return minValue;
}

template<class T>
T Matrix<T>::GetMaxValue()
{
		T maxValue = m_ppMatrix[0][0];
		int i,j;

		for (i=0; i<m_nYSize; i++)
		for (j=0; j<m_nXSize; j++)
		{
			if(m_ppMatrix[i][j]>maxValue)
				maxValue = m_ppMatrix[i][j];
		}
		return maxValue;
}

template<class T>
Matrix<T> Matrix<T>::operator+ (const T& item)
{
		int i, j;

		Matrix<T> mtrx(m_nYSize, m_nXSize);
		for (i=0; i<m_nYSize; i++)
		for (j=0; j<m_nXSize; j++)
		{
			mtrx.m_ppMatrix[i][j] = m_ppMatrix[i][j]+item ;
		}
		return mtrx;
}

template<class T>
Matrix<T> Matrix<T>::operator- (const T& item)
{
		int i, j;

		Matrix<T> mtrx(m_nYSize, m_nXSize);
		for (i=0; i<m_nYSize; i++)
		for (j=0; j<m_nXSize; j++)
		{
			mtrx.m_ppMatrix[i][j] = m_ppMatrix[i][j]-item ;
		}
		return mtrx;
}

template<class T>
Matrix<T>::~Matrix()
{
	if (m_bCreated)
	{
		delete [] m_ppMatrix[0];
		delete [] m_ppMatrix;
	}
}

template<class T>
int Matrix<T>::GetXSize()
{
	return m_nXSize;
}

template<class T>
T Matrix<T>::SumAll()
{
	T sum = 0;
	int i, j;

	for (i=0; i<m_nYSize; i++)
	for (j=0; j<m_nXSize; j++)
	{
		sum += m_ppMatrix[i][j];
	}
	return sum;
}

template<class T>
int Matrix<T>::GetYSize()
{
	return m_nYSize;
}
template<class T>        //Y(row) X(col)      
T& Matrix<T>::operator()(int i, int j)
{
	ASSERT(i>=0 && i<m_nYSize &&
		   j>=0 && j<m_nXSize);

	return m_ppMatrix[i][j];
}

//Fancy Indexing
template<class T> 
Container2DRow<T> Matrix<T>::operator [] (int i)
{
	ASSERT(i>=0 && i<m_nYSize); 
    row.i = i;
    return row;
}

template<class T> 
const Container2DRow<T> Matrix<T>::operator [] (int i) const
{
	ASSERT(i>=0 && i<m_nYSize); 
    row.i = i;
    return row;
}