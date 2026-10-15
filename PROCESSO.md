# PROCESSO.md — Lab 1 · Pisca-LED

**Aluno:** Julia Jesus Bezerra · julia.bezerra@sou.inteli.edu.br
**Turma / grupo:** T26 · Grupo 2

## 1. Contextualizar
- **Objetivo:** Quando o dispositivo estiver ligado e funcionando o LED de status deve indicar isso.
- **Comportamento esperado:** A cada 2s o LED de status será acesso ao receber um pulso de 200ms.
- **Critério de aceitação:** A corrente recomendada pelo datasheet é de 20 mA, sabendo disso a corrente calculada ficou abaixo desse valor. Além disso, o ciclo cronometrado fica entre 1,9s e 2,1s.
- **Delegação à IA × feito sozinho:** Monto o sistema sozinha, mas uso a IA para tirar dúvidas que aparecem no meio do caminho.

## 2. Consultar
- **Ferramenta:** ChatGPT
- **Pergunta (exata):** Ao usar arduino, como em um um sistema de LED de status, como eu poderia fazer para que o tempo piscar, remete - se a status diferentes?? Exemplo: mais rápido para ponto de atenção e "normal" para indicar que está tudo certo).
- **Resposta resumida:** Você pode alterar os tempos de delay() conforme o status desejado, usando if ou switch.
Exemplo baseado no seu código:
const int PINO_LED = 8;

void setup() {
  pinMode(PINO_LED, OUTPUT);
}

void loop() {
  // Status NORMAL: pisca lentamente
  digitalWrite(PINO_LED, HIGH);
  delay(200);
  digitalWrite(PINO_LED, LOW);
  delay(1800);

  // Para testar ATENÇÃO, use:
  // delay(300); // intervalo menor = pisca mais rápido
}


Sugestão de intervalos:
- 🟢 Normal: 200 ms aceso + 1800 ms apagado.
- 🟡 Atenção: 200 ms aceso + 300 ms apagado.
- 🔴 Erro: 100 ms aceso + 100 ms apagado.
Para alternar automaticamente entre os status, você pode usar uma variável statusAtual e um switch para selecionar os tempos.

## 3. Confrontar
- **Afirmação conferida:** Pela Lei de Ohm, a corrente que passa pelo LED é calculada pela tensão da fonte menos a queda de tensão do LED, dividida pela resistência:
\[
I = \frac{5V-2V}{R} = \frac{3V}{R}
\]

Com um resistor de 220 Ω:
\[
I = \frac{3}{220} \approx 0{,}0136\,A
\]

Resultado: aproximadamente 13,6 mA, uma corrente adequada para muitos LEDs vermelhos comuns.
- **Fonte primária:** Lei de Ohm (cálculo)
- **Trecho / cálculo:** I = V / R
- **Veredito:** Confirmada
- **ADR:** Aceito a resposta da IA, porque ela utiliza o calculo da Lei de Ohm da forma correta.

## 4. Construir
- **Wokwi:** https://wokwi.com/projects/477970487446530049
- **Repositório / commit:** https://github.com/juliabezerra-star/aula1
- **Ciclo medido:** 2.009 s
- **Corrente calculada com 220 Ω:** 13.64 mA
- **Projeto funcionando:** sim

## 5. Comprovar (sem IA)
1. **Corrente com 330 Ω:** 9.09 mA — cálculo: I = (5 - 2) / 330 = 0,00909
2. **Resistor de 0 Ω:** Porque nada limita a corrente, que passa muito do máximo suportado pelo LED. — Isso acontece porque o resistor funciona como um limitador da corrente elétrica, ou seja, sem ele (resistência de 0 Ω) passa corrente excessiva pelo LED, o que pode superaquecer e queimar o LED.
3. **LED no pino 12:** Só o valor de PINO_LED passa a ser 12 (e o fio vai para o pino 12).
4. **TEMPO_APAGADO para 500 ms a cada 3 s:** 2500 ms

Declaro que respondi a etapa Comprovar sem IA: sim
