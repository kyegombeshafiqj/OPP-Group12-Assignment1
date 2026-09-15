//Group 12 - argsort() implementation
void argsortData(int scores[], int indices[],int n){
    for (int i = 0; i < n; i++)
    {
        indices[i] = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (scores[indices[i]] > scores[indices[j]])
            {
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
            
        }
        
    }
    
}