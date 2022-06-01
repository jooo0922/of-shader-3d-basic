#version 410

in vec2 fragUV; // 버텍스 셰이더에서 받아온 torus 모델의 uv좌표데이터

out vec4 outCol; // 최종 출력할 색상을 계산하여 다음 파이프라인으로 넘겨줄 변수

void main(){
  outCol = vec4(fragUV, 0.0, 1.0); // r, g 값에 uv좌표를 각각 넣어 색상을 출력함. (uv좌표로 색상을 출력하는 디버깅 기법은 p.74 ~ 75 참고)
}