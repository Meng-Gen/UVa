#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>

int n;
int m;
int c;
double rating_matrix[52][202] = {};
double similarity_matrix[202][202] = {};

// ----------------------------------------------------------------------------

void ReadProblemSettings()
{
    std::cin >> n >> m >> c;
}

// ----------------------------------------------------------------------------

void ReadRatingMatrix()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            rating_matrix[i][j] = -1.0;
        }
    }

    int user;
    int movie;
    double rating;
    for (int i = 0; i < c; i++)
    {
        std::cin >> user >> movie >> rating;
        rating_matrix[user][movie] = rating;
    }
}

// ----------------------------------------------------------------------------

void BuildSimilarityMatrix()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = i; j <= m; j++)
        {
            double rating_diff = 0.0;
            for (int k = 1; k <= n; k++)
            {
                double rating_i = rating_matrix[k][i];
                double rating_j = rating_matrix[k][j];
                if ((rating_i > 0.0) && (rating_j > 0.0))
                {
                    double diff = rating_i - rating_j;
                    rating_diff = rating_diff + diff * diff;
                }
            }
            similarity_matrix[i][j] = 1.0/(1.0 + rating_diff);
            similarity_matrix[j][i] = similarity_matrix[i][j];
        }
    }
}

// ----------------------------------------------------------------------------

struct Prediction
{
    int movie_;
    double score_;

    Prediction(int movie, double score) : movie_(movie), score_(score) { } 
};

bool CompareDelegate(const Prediction& a, const Prediction& b)
{
    return a.score_ > b.score_;
}

void Recommend(int user)
{
    std::vector<Prediction> predictions;
    for (int i = 1; i <= m; i++)
    {
        if (rating_matrix[user][i] < 0.0)
        {
            bool is_similar = false;
            double numerator = 0.0;
            double denominator = 0.0;
            for (int j = 1; j <= m; j++)
            {
                if (rating_matrix[user][j] < 0.0) 
                {
                    continue;
                }
                is_similar = true;
                numerator += 
                    (similarity_matrix[i][j] * rating_matrix[user][j]);
                denominator += similarity_matrix[i][j];
            }

            // Note that in the formula above, if the denominator is zero, 
            // which means movie i is not at all similar to any movie 
            // he watched, we should not recommend this movie.
            if (is_similar)
            {
                double score = numerator / denominator;
                predictions.push_back(Prediction(i, score));
            }
        }
    }
    std::sort(predictions.begin(), predictions.end(), CompareDelegate);

    printf("Recommendations for user %d:\n", user);
    for (unsigned int i = 0; i < predictions.size(); i++)
    {
        if (i > 9)
        {
            break;
        }
        printf("%d %.3lf\n", predictions[i].movie_, predictions[i].score_);
    }
    putchar('\n');
}

// ----------------------------------------------------------------------------

void MakeRecommendations()
{
    int user;
    while (std::cin >> user)
    {
        Recommend(user);
    }
}

// ----------------------------------------------------------------------------

int main(int argc, char* argv[]) 
{
    ReadProblemSettings();
    ReadRatingMatrix();
    BuildSimilarityMatrix();
    MakeRecommendations();
    return 0;
}