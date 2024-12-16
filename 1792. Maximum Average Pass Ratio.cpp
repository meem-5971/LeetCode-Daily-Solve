/* class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        vector<double>PR(n);

        for(int i=0;i<n;i++){
            double ratio =(double) classes[i][0]/classes[i][1];
            PR[i]=ratio;
        }
        while(extraStudents--){
            vector<double>updatedPR(n);

            for(int i=0;i<n;i++){
                double newRatio=(double) (classes[i][0]+1)/(classes[i][1]+1);
                updatedPR[i]=newRatio;
            }
            int bestclassId=0;
            double bestdiff=0;

            for(int i=0;i<n;i++){
                double diff =updatedPR[i]-PR[i];
                if(diff >bestdiff){
                    bestdiff=diff;
                    bestclassId=i;
                }
            }
            PR[bestclassId]=updatedPR[bestclassId];
            classes[bestclassId][0]++;
            classes[bestclassId][1]++;
        }
        double res=0.0;
        for(int i=0;i<n;i++){
            res+=PR[i];
        }
        return res/n;
    }
}; */
/* class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        vector<double>PR(n);

        for(int i=0;i<n;i++){
            double ratio =(double) classes[i][0]/classes[i][1];
            PR[i]=ratio;
        }
        while(extraStudents--){
            vector<double>updatedPR(n);

            for(int i=0;i<n;i++){
                double newRatio=(double) (classes[i][0]+1)/(classes[i][1]+1);
                updatedPR[i]=newRatio;
            }
            int bestclassId=0;
            double bestdiff=0;

            for(int i=0;i<n;i++){
                double diff =updatedPR[i]-PR[i];
                if(diff >bestdiff){
                    bestdiff=diff;
                    bestclassId=i;
                }
            }
            PR[bestclassId]=updatedPR[bestclassId];
            classes[bestclassId][0]++;
            classes[bestclassId][1]++;
        }
        double res=0.0;
        for(int i=0;i<n;i++){
            res+=PR[i];
        }
        return res/n;
    }
}; */
class Solution {
public:
#define P pair<double,int>
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
      int n=classes.size();  

      priority_queue<P>pq;

      for(int i=0;i<n;i++){
        double cur_PR =(double)classes[i][0]/classes[i][1];
        double new_PR =(double)(classes[i][0]+1)/(classes[i][1]+1);
        double diff=new_PR-cur_PR;
        pq.push({diff,i});
      }

      while(extraStudents--){
        auto curr=pq.top();
        pq.pop();

        double diff=curr.first;
        int id=curr.second;

        classes[id][0]++;
        classes[id][1]++;

        double cur_PR =(double)classes[id][0]/classes[id][1];
        double new_PR =(double)(classes[id][0]+1)/(classes[id][1]+1);
        diff=new_PR-cur_PR;
        pq.push({diff,id});
      }
       double res=0.0;
        for(int i=0;i<n;i++){
            res+=(double)classes[i][0]/classes[i][1];
        }
        return res/n;
    }
};