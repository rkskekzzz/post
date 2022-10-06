#include<iostream>
#include<vector>

int k;

struct point {
	int x;
	int y;
};

struct cluster {
	int center_x;
	int center_y;
	int size;
	int calculated_center_x;
	int calculated_center_y;
	point *points;
};

std::vector<point> points;
std::vector<cluster> clusters;


void init_points() {
	for (int i = 0; i < 100; i++) {
		point p;
		p.x = rand() % 100;
		p.y = rand() % 100;
		points.push_back(p);
	}
}

point find_point_with_max_distance_by_min_distance_of_clusters_center() {
	int max_distance = 0;
	point max_distance_point;
	for (size_t i = 0; i < points.size(); i++) {
		int min_distance = 100000;
		for (size_t j = 0; j < clusters.size(); j++) {
			int distance = abs(points[i].x - clusters[j].center_x) + abs(points[i].y - clusters[j].center_y);
			if (distance < min_distance) {
				min_distance = distance;
			}
		}
		if (min_distance > max_distance) {
			max_distance = min_distance;
			max_distance_point = points[i];
		}
	}
	return max_distance_point;
}

void init_clusters() {
	cluster first_cluster;
	first_cluster.center_x = points[0].x;
	first_cluster.center_y = points[0].y;
	first_cluster.size = 0;
	first_cluster.points = new point[100];
	clusters.push_back(first_cluster);
	for (int i = 1; i < k; i++) {
		cluster new_cluster;
		point p = find_point_with_max_distance_by_min_distance_of_clusters_center();
		new_cluster.center_x = p.x;
		new_cluster.center_y = p.y;
		new_cluster.size = 0;
		clusters.push_back(new_cluster);
	}
}

// make {0, 0}, {5, 5}, {5, 0}, {0, 5}, {3, 3} points
void init_static_points() {
	point p;
	p.x = 0;
	p.y = 0;
	points.push_back(p);
	p.x = 5;
	p.y = 5;
	points.push_back(p);
	p.x = 5;
	p.y = 0;
	points.push_back(p);
	p.x = 0;
	p.y = 5;
	points.push_back(p);
	p.x = 3;
	p.y = 3;
	points.push_back(p);
}


void print_clusters() {
	for (size_t i = 0; i < clusters.size(); i++) {
		std::cout << "cluster " << i << " : " << clusters[i].center_x << ", " << clusters[i].center_y << std::endl;
	}
}

void print_points() {
	for (size_t i = 0; i < points.size(); i++) {
		std::cout << "point " << i << " : " << points[i].x << ", " << points[i].y << std::endl;
	}
}

bool checkfinish() {
	for (size_t i = 0; i < clusters.size(); i++) {
		if (clusters[i].center_x != clusters[i].calculated_center_x || clusters[i].center_y != clusters[i].calculated_center_y) {
			return false;
		}
	}
	return true;
}
// calculate center is center of whole cluster point
void calculate_clusters_center() {
	for (size_t i = 0; i < clusters.size(); i++) {
		int sum_x = 0;
		int sum_y = 0;
		for (size_t j = 0; j < clusters[i].size; j++) {
			sum_x += clusters[i].points[j].x;
			sum_y += clusters[i].points[j].y;
		}
		clusters[i].calculated_center_x = sum_x / clusters[i].size;
		clusters[i].calculated_center_y = sum_y / clusters[i].size;
	}
}

void push_points_to_cluster_by_min_distance() {
	for (size_t i = 0; i < points.size(); i++) {
		int min_distance = 100000;
		int min_distance_cluster_index = 0;
		for (size_t j = 0; j < clusters.size(); j++) {
			int distance = abs(points[i].x - clusters[j].center_x) + abs(points[i].y - clusters[j].center_y);
			if (distance < min_distance) {
				min_distance = distance;
				min_distance_cluster_index = j;
			}
		}
		clusters[min_distance_cluster_index].points[clusters[min_distance_cluster_index].size] = points[i];
		clusters[min_distance_cluster_index].size++;
	}
}

void print_clusters_points() {
	for (size_t i = 0; i < clusters.size(); i++) {
		std::cout << "cluster " << i << " : " << clusters[i].center_x << ", " << clusters[i].center_y << std::endl;
		for (size_t j = 0; j < clusters[i].size; j++) {
			std::cout << "point " << j << " : " << clusters[i].points[j].x << ", " << clusters[i].points[j].y << std::endl;
		}
	}
}

int main(void) {
	std::cout << "Enter the number of clusters: ";
	std::cin >> k;

	FILE *fp = fopen("input.txt", "r");
	// read points from file
	while (!feof(fp)) {
		point p;
		fscanf(fp, "%d %d", &p.x, &p.y);
		points.push_back(p);
	}

	print_points();
	init_static_points();
	init_clusters();
	test_init_points();
	push_points_to_cluster_by_min_distance();
	while (true) {
		calculate_clusters_center();
		if (checkfinish()) {
			break;
		}
		for (size_t i = 0; i < clusters.size(); i++) {
			clusters[i].center_x = clusters[i].calculated_center_x;
			clusters[i].center_y = clusters[i].calculated_center_y;
			clusters[i].size = 0;
			delete[] clusters[i].points;
			clusters[i].points = new point[100];
		}
		push_points_to_cluster_by_min_distance();
		print_clusters_points();
	}
	print_clusters_points();
	return 0;
}
