/* 
 * File:   djGraph.h
 * Author: Cesar Carrillo
 *
 * Created on March 30, 2016, 9:45 AM
 */

#ifndef DJGRAPH_H
#define	DJGRAPH_H

#include <iostream>
#include <string>
#include <list>
#include "minHeap.h"
#include "myVector.h"
#include <cmath>
using namespace std;

class djGraph{
private:
    int size=0;
        class edge;
	class vertex{
	public:
		int data;
                double weight = INFINITY;
		vector<edge *> neighbors;
                vertex * from;
                 int minPos = -1;
                 bool inserted = false;
                vertex(){}
		vertex(double x)
		{   
                    from = NULL;
                    data = x;
		}
                void setWeight(double x){
                    if(x < weight){
                        weight = x;
                    }
                }
    	};
       class edge{
                   public: 
                    double weight;
                    vertex * to;
                    edge(){}
                      edge(double w, vertex * t){
                         weight = w;
                         to = t;
                     }
         };

	vector <vertex *> verticeList;

        string flip(vertex * x){
            if(x->from == NULL)
                return "";
            else{
                return print(x->data) + flip(x->from);
            }     
        }
        string print(int some){
            cout<<some<<endl;
            return" ";
        }
        

public:
        djGraph(){};
        djGraph(int vertices){
            
            for(int x= 0; x<=vertices; x++){
                verticeList.push_back(new vertex(x));
            }
        }
	void addEdge(int x, int y, double weight){
		vertex * one = verticeList[x];
		vertex * two = verticeList[y];
		one->neighbors.push_back(new edge(weight, two));
	}

        void shortestPath(int start, int end) {
		minHeap<vertex *> list;
		list.resize(verticeList.size());
		verticeList[start]->weight = 0;
		verticeList[start]->minPos = 0;
		vector <bool> visited;
		visited.resize(verticeList.size());

		for(int x=0; x<verticeList.size(); x++)
                    list.insert(verticeList[x]);
		while (!list.empty()) {
			vertex * temp = list.extractMin();
                        if(temp->data == end){//finishing statement.
                                vertex * last = verticeList[end];
                                cout << "Total weight taken from " << start << " to " << last->data << " is " << (int)last->weight << endl;
                                flip(last);
                                return;
                        }
                        for (int x = 0; x<temp->neighbors.size(); x++) {
                            if (temp->neighbors[x]->to->weight > (temp->neighbors[x]->weight + temp->weight)){
                                relax(temp, temp->neighbors[x]->to , temp->neighbors[x]->weight);
                                list.changeValueAt(temp->neighbors[x]->to->minPos , temp->neighbors[x]->to);
                            }
                        }
                    }
                }
        void relax(vertex * original , vertex * &neigh , double weightBetween){
            if(neigh->weight > (original->weight + weightBetween)){
                neigh->weight = (original->weight + weightBetween);
                neigh->from = original;
            }
        }
};


#endif	/* DJGRAPH_H */

/*
 Total weight taken from 42615 to 264340 is 654710
42632
42616
39590
42652
42569
42566
42565
42563
42564
42573
42663
42662
43849
43850
43851
43852
44196
44198
44197
44202
44203
44267
44296
44298
44317
44325
44327
44328
44329
44552
44591
44592
44593
44594
44595
44624
44628
44629
44630
35716
35715
35768
35831
35836
35835
35846
35851
35854
35856
35876
35883
35886
35887
37731
37741
37755
37757
37798
37801
37823
37832
38025
38034
38041
38076
38089
38093
38103
38110
38686
38688
38706
38713
38730
38729
38732
38738
38785
38786
38803
38809
38808
38972
41553
41559
41563
41566
41577
41582
41587
41585
41590
41600
41604
41607
41622
41623
41626
41628
41631
41635
41636
48388
48395
48398
48399
48594
48612
48633
48635
48642
48643
48644
53408
53409
53413
53439
53440
53443
53451
53452
53460
53463
53464
53478
53482
53484
53506
53561
53565
53567
53568
53606
53607
53653
53654
53657
53659
53658
53656
53655
53393
53394
53390
53391
52758
52759
52760
52765
52764
50647
50648
50646
50649
27432
27433
27421
27422
27425
27426
27427
27428
27429
27430
27431
28134
28135
28145
28146
28147
28148
28149
28154
28150
28153
28156
28152
28160
27794
27789
28122
28123
28124
28125
28128
28132
28133
28705
28708
28706
28707
28709
28710
28711
28657
28653
28652
28649
28650
28646
28648
28644
28642
28643
28645
28666
28667
28668
28669
28790
28805
28804
28806
24082
24081
24089
24098
24237
24240
24174
24172
24177
24211
24214
24225
24202
24203
24207
24205
24199
24197
24198
24784
24785
24788
23713
23711
23721
23723
23725
23729
23730
23765
23768
23791
24895
24897
24901
25062
25064
25070
25090
25147
25149
24028
25152
34161
187206
187205
187637
187197
187198
187256
186192
132852
132853
132849
132850
132851
132863
132862
132858
132859
132760
132810
132791
132792
132727
132722
132715
132717
132938
132944
132952
132962
132968
133005
132999
133001
133000
132987
132667
132668
139598
132665
132664
132666
249022
249019
249018
249008
248993
249007
248987
248992
248997
248984
248995
248938
248924
248933
248930
248929
248928
248912
248896
248870
248875
248874
248872
248869
248862
248808
248859
248863
248861
248864
248509
248513
248506
248510
248522
241917
248521
248500
248498
248495
248494
248493
248428
248584
248581
248582
248580
248579
248560
248573
248558
248556
248571
248566
248570
248565
248567
248564
240441
240439
240432
240430
240427
240428
240429
240431
241826
241830
241858
241837
241838
241885
241886
241899
241889
241906
241890
264340

RUN SUCCESSFUL (total time: 9s)
*/