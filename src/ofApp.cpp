#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex(); // 스크린 픽셀 좌표를 사용하는 텍스쳐 관련 오픈프레임웍스 레거시 지원 설정 비활성화. (uv좌표계랑 다르니까!)
    ofEnableDepthTest(); // 깊이테스트를 활성화하여 z좌표값을 깊이버퍼에 저장해서 z값을 기반으로 앞뒤를 구분하여 렌더링할 수 있도록 함.
    
    /**
     2D 메쉬와 다르게 3D 메쉬는
     버텍스를 일일이 추가할 수 없을 정도로 복잡하기 때문에,
     일반적으로 외부 모델링 파일을 로드하여 사용하는 경우가 많음.
     
     오픈프레임웍스는 기본적으로 .ply 포맷의 모델링 파일을 지원하며,
     ofMesh 객체의 load() 함수를 이용해서 간단하게 모델을 불러올 수 있음.
     
     셰이더, 텍스쳐 파일과 마찬가지로, bin/data 디렉토리에
     모델링 파일을 저장해뒀다면, 파일명만 인자로 넣어줘도
     알아서 로드해 옴.
     */
    torusMesh.load("torus.ply");
    uvShader.load("passthrough.vert", "uv_vis.frag"); // torus 메쉬에 적용할 셰이더 파일 로드
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    using namespace glm; // 이제부터 현재 블록 내에서 glm 라이브러리에서 꺼내 쓸 함수 및 객체들은 'glm::' 을 생략해서 사용해도 됨.
    
    // uvShader 를 바인딩하여 사용 시작
    uvShader.begin();
    
    uvShader.setUniformMatrix4f("mvp", mat4()); // 일단 테스트삼아 단위행렬을 mvp 행렬로 보내주도록 함. (그냥 glm::mat4() 호출하면 단위행렬이 리턴된다고 했지?)
    torusMesh.draw(); // torus 메쉬 드로우콜 호춣여 그려줌
    
    uvShader.end();
    // uvShader 사용 중단
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
