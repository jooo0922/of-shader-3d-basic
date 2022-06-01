#version 410

// layout 을 이용해서 버텍스 셰이더에세 각 버텍스 데이터가 저장된 순서를 알려줌. (오픈프레임웍스가 버텍스 데이터를 저장하는 순서는 p.74 참고)
layout(location = 0) in vec3 pos;
layout(location = 3) in vec2 uv;

/*
  mvp 행렬 - 모델행렬, 뷰행렬, 투영행렬 합치기

  대부분의 게임은 최적화를 위해
  model, view, projection 행렬들을
  c++ 단에서 하나로 합쳐서 셰이더에 전송해 줌.

  그렇게 하면, 버텍스마다 
  투영행렬 * 뷰행렬 * 모델행렬 * 버텍스 위치
  순으로 동일한 행렬을 중복해서 곱해주지 않고,
  
  c++ 단에서 한 번만 곱해서
  버텍스 셰이더에 유니폼 변수로 쏴주면 
  행렬 곱셈 연산을 줄일 수 있음.
*/
uniform mat4 mvp;

out vec2 fragUV; // 프래그먼트 셰이더로 전송할 torus 모델의 uv좌표 데이터 (uv좌표로 색상을 찍는 디버깅 기법을 사용할 것이기 때문!)

void main() {
  gl_Position = mvp * vec4(pos, 1.0);
  fragUV = uv;
}