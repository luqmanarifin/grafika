#ifndef __Pau_H_
#define __Pau_H_

#include <shape.h> 
struct Pau : public Shape {
	Pau(){
 // bawah
    addPolygon(Polygon()
		.addPoint(Point<double>(700,400,0))
		.addPoint(Point<double>(100,400,0))
		.addPoint(Point<double>(100,400,-200))
		.addPoint(Point<double>(700,400,-200))	
		.addPoint(Point<double>(700,500,-200))
		.addPoint(Point<double>(100,500,-200))
		.addPoint(Point<double>(100,500,0))
		.addPoint(Point<double>(700,500,0))
		.setColor(Color::GREEN)	
	);
	//tengah
  addPolygon(Polygon()
		.addPoint(Point<double>(600,500,0))
		.addPoint(Point<double>(100,500,0))
		.addPoint(Point<double>(100,500,-200))
		.addPoint(Point<double>(600,500,-200))	
		.addPoint(Point<double>(600,600,-200))
		.addPoint(Point<double>(100,600,-200))
		.addPoint(Point<double>(100,600,0))
		.addPoint(Point<double>(600,600,0))
		.setColor(Color::GREEN)	
	);
	//atas
  addPolygon(Polygon()
		.addPoint(Point<double>(500,600,0))
		.addPoint(Point<double>(100,600,0))
		.addPoint(Point<double>(100,600,-200))
		.addPoint(Point<double>(500,600,-200))	
		.addPoint(Point<double>(500,800,-200))
		.addPoint(Point<double>(100,800,-200))
		.addPoint(Point<double>(100,800,0))
		.addPoint(Point<double>(500,800,0))
		.setColor(Color::GREEN)		
	);
	
	//kanan1
  addPolygon(Polygon()
		.addPoint(Point<double>(700,400,0))
		.addPoint(Point<double>(700,500,0))
		.addPoint(Point<double>(700,500,-400))
		.addPoint(Point<double>(700,400,-400))	
		.setColor(Color::GREEN)	
	);	
	//kanan2
  addPolygon(Polygon()
		.addPoint(Point<double>(600,400,0))
		.addPoint(Point<double>(700,400,0))
		.addPoint(Point<double>(700,400,-200))	
		.addPoint(Point<double>(600,400,-200))	
		.setColor(Color::BLUE)	
	);
	//kanan3
  addPolygon(Polygon()
		.addPoint(Point<double>(600,500,0))
		.addPoint(Point<double>(600,600,0))
		.addPoint(Point<double>(600,600,-400))
		.addPoint(Point<double>(600,500,-400))	
		.setColor(Color::RED)		
	);	
	//kanan4
  addPolygon(Polygon()
		.addPoint(Point<double>(500,400,0))
		.addPoint(Point<double>(600,400,0))
		.addPoint(Point<double>(600,400,-200))	
		.addPoint(Point<double>(500,400,-200))		
		.setColor(Color::YELLOW)		
	);
	//kanan5
  addPolygon(Polygon()
		.addPoint(Point<double>(500,600,0))
		.addPoint(Point<double>(500,600,-200))
		.addPoint(Point<double>(500,800,-200))
		.addPoint(Point<double>(500,800,0))	
		.setColor(Color::BLUE)	
	);


	//kiri
  addPolygon(Polygon()
		.addPoint(Point<double>(100,400,0))
		.addPoint(Point<double>(100,800,-400))
		.addPoint(Point<double>(100,400,0))
		.addPoint(Point<double>(100,800,-400))	
		.setColor(Color::RED)	
	);	
  //atap
  addPolygon(Polygon()
		.addPoint(Point<double>(100,800,0))
		.addPoint(Point<double>(500,800,0))
		.addPoint(Point<double>(100,800,-400))
		.addPoint(Point<double>(500,800,-400))	
		.setColor(Color::GREEN)
	);
  }
};

#endif
