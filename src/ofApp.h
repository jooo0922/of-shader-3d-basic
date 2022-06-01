#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        ofMesh torusMesh; // torus.ply 모델링 파일을 로드해서 사용할 메쉬 객체 변수 선언
        ofShader uvShader; // torus.ply 모델의 버텍스 uv좌표를 색상 데이터로 사용할 셰이더 객체 변수 선언
};
