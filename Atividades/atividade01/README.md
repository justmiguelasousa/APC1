programa
{
	funcao inicio()
	{
		// Declaração de constantes
		const real VALOR_TICKET = 12.50
		const real VALOR_CAFE = 4.00

		// Declaração de variáveis
		inteiro qtd_refeicoes, qtd_cafes
		real saldo_conta, total_cafe, total_ticket, total_gasto, saldo_restante

		// Leitura dos dados
		escreva("Digite a quantidade de refeições: ")
		leia(qtd_refeicoes)

		escreva("Digite a quantidade de cafés: ")
		leia(qtd_cafes)

		escreva("Digite o saldo da sua conta: ")
		leia(saldo_conta)

		// Processamento / Cálculos
		total_cafe = qtd_cafes * VALOR_CAFE
		total_ticket = qtd_refeicoes * VALOR_TICKET
		total_gasto = total_cafe + total_ticket
		saldo_restante = saldo_conta - total_gasto

		// Exibição dos resultados
		escreva("\n--- RESUMO DO GASTO ---\n")
		escreva("Total gasto com café: R$ ", total_cafe, "\n")
		escreva("Total gasto com refeições: R$ ", total_ticket, "\n")
		escreva("Total geral gasto: R$ ", total_gasto, "\n")
		escreva("Saldo restante: R$ ", saldo_restante, "\n")
	}
}