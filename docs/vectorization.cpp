class Color {
	red;
	green;
	blue;
	bightness;
	enum binary_color {
		turn_on,
		turn_off
	}
}

enum VisitState {
	unvisited,
	visited,
	excluded
}

class Point(){
	Color color;
	Coord coord;
	VisitState state;
}

class VectorizationState(){
	Point start;
	Point current;
	Point previous;
	vector<Point> neighbours;
	vector<Point> nexts {
		vector<Point> result;
		for (Point n : neighbours) {
			if (n.state == VisitState.unvisited){
				result.add(n);
			}
		}
		return result;
	}
}

class Image {
	Image(IImage img){
		img -> data;
	}
	
	vector<Point> get_first_unvisited(){
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (data[i][j].state == VisitState.unvisited &&
					data[i][j].brightness == Color.binary_color.turn_on) {
					return data[i][j].state;
				}
			}
		}
	}
	
	bool has_unvisited_points(){
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (data[i][j].state == VisitState.unvisited &&
					data[i][j].color.brightness == Color.binary_color.turn_on) {
					return true;
				}
			}
		}
		return false;
	}
	
	vector<Point> get_neighbours(Point point) {
		vector<Point> neighbours;
		
		for (int i =- 1; i <= 1; i++) {
			for (int j =- 1; j <= 1; j++) {
				row = point.coord.x + i;
				col = point.coord.y + j;
				
				if ((0 < row || row <= rows || 0 < col || col <= cols) &&
					data[row][col].color.bightness == Color.binary_color.turn_on &&
					data[row][col].state != VisitState.excluded) {
					neighbours.add(data[row][col]);
				}
			}
		}
	
	
	void convert_all_excluded_to_unvisited() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (data[i][j].state == VisitState.excluded) {
					data[i][j].state = VisitState.unvisited;
				}
			}
		}
	}

	Point get_horizontal_or_vertical_neighbour(Point center, vector<Point> neighbours) {
		for (Point n : neighbours) {
			if (center.coord.x + 1 == n.coord.x && center.coord.y == n.coord.y ||
				center.coord.x - 1 == n.coord.x && center.coord.y == n.coord.y ||
				center.coord.x == n.coord.x && center.coord.y + 1 == n.coord.y ||
				center.coord.x == n.coord.x && center.coord.y - 1 == n.coord.y) {
				return n;
			}
		}
		return null;
	}
	
	Point get_horizontal_or_vertical_neighbour(Point center) {
		return get_horizontal_or_vertical_neighbour(center, get_neighbours(center));
	}
	
	int rows;
	int cols;
	data;
}

class Object {
	
}

class IntersectionPoint {
	Coord coord;
	// Пересекающиеся объекты
	vector<Object> objects;
}

class Line : Object {
	Line(Point begin, Point end);
	Line(Point begin, Point end, vector<IntersectionPoint> intersections);
	
	Point begin;
	Point end;
	vector<IntersectionPoint> intersections;
}

class Functions {
	bool is_aligned(Point a, Point b, Point c);
	bool is_right_angle(Point a, Point b, Point c);
}

void Vectorization(IImage img){
	VisitState vs = null;
	Image image = new Image(img);
	vector<Object> objects;
	vector<IntersectionPoint> intersections;
	
	while(image.has_unvisited_points()){
		
		if(vs == null){
			image.convert_all_excluded_to_unvisited();
			
			Point point = image.get_first_unvisited();
			if(point != null){
				vs == new VisitState();
				vs.current = point;
			}
		}
		
		vector<Point> neighbours = image.get_neighbours(vs.current);
		
		switch (neighbours.count) {
			case 0:
				vs.current.state = VisitState.visited;
				break;
				
			case 1:
				vs.current.state = VisitState.visited;
				if (vs.previous == null) {
					vs.previous = vs.current;
					vs.start = vs.current;
					vs.current = neighbours[0];
				} else {
					objects.add(new Line(vs.start, vs.current));
					vs = null;
				}
				break;
				
			case 2:
				if (vs.previous == null) {
					// Определяем следующую точку
					vector<Point> nexts = vs.nexts;
					Point next = image.get_horizontal_or_vertical_neighbour(vs.current, nexts);
					if (next == null) {
						next = neighbours[0];
					}
					
					// Скрываем остальные (не являющиеся следующей)
					for (Point n : nexts) {
						if (n != next) {
							n.state = VisitState.excluded;
						}
					}
					
					// Переход в следующую точку
					vs.previous = vs.current;
					vs.start = vs.current;
					vs.current = next;
					
					// Пометить текущую как прочитанную
					//TODO
				} else {
					vs.current.state = VisitState.visited;
					
					if (!Functions.is_aligned(vs.previous, vs.current, next)) {
						objects.add(new Line(vs.start, vs.current));
					}
					
					vs.previous = vs.current;
					vs.start = vs.current;
					vs.current = next;
				}
				break;
				
			case 3:
				if (vs.previous == null) {
					// Определяем следующую точку
					vector<Point> nexts = vs.nexts;
					Point next = image.get_horizontal_or_vertical_neighbour(vs.current, nexts);
					if (next == null) {
						next = neighbours[0];
					}
					
					// Пометить текущую как прочитанную
					//TODO: Here?
					
					// Скрываем остальные (не являющиеся следующей)
					for (Point n : nexts) {
						if (n != next) {
							n.state = VisitState.excluded;
						}
					}
					
					// Переход в следующую точку
					vs.previous = vs.current;
					vs.start = vs.current;
					vs.current = next;
					
					// Пометить текущую как прочитанную
					//TODO: Or here?
				} else {
					// Определяем следующую точку
					vector<Point> nexts = vs.nexts;
					Point next = null;
					for (Point n : next) {
						if (Functions.is_aligned(vs.previous, vs.current, n) {
							next = n;
							break;
						}
					}
					
					if (next == null) {
						next = neighbours[0];
					}
					
					// Пометить текущую как прочитанную
					
				}

			case ...:
				if (vs.previous == null) {
 					// Определяем следующую точку
 					vector<Point> nexts = vs.nexts;
					
					Point next = image.get_horizontal_or_vertical_neighbour(vs.current, nexts);
					if (next == null) {
						next = nexts[0];
					}

					// Исключаем другие точки
					for (Point n : nexts) {
						if (n != next) {
							n.state = VisitState.excluded;
						}
					}

					// Меняем состояние текущей точки
					bool has_excluded = false;
					for (Point n : nexts) {
						if(n.state == VisitState.excluded) {
							has_excluded = true;
							break;
						}
					}
					vs.current.state = has_excluded ? VisitState.excluded : VisitState.visited;

					// Переходим в следующую точку
					vs.start = vs.current;
					vs.previous = vs.current;
					vs.current = next;
				} else {
					
				}
		}
	}
}




