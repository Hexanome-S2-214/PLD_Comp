// Generated from /home/tboyer/INSA/4A/S2/PLD-COMP/PLD_Comp/compiler/src/ifcc.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link ifccParser}.
 */
public interface ifccListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link ifccParser#axiom}.
	 * @param ctx the parse tree
	 */
	void enterAxiom(ifccParser.AxiomContext ctx);
	/**
	 * Exit a parse tree produced by {@link ifccParser#axiom}.
	 * @param ctx the parse tree
	 */
	void exitAxiom(ifccParser.AxiomContext ctx);
	/**
	 * Enter a parse tree produced by {@link ifccParser#prog}.
	 * @param ctx the parse tree
	 */
	void enterProg(ifccParser.ProgContext ctx);
	/**
	 * Exit a parse tree produced by {@link ifccParser#prog}.
	 * @param ctx the parse tree
	 */
	void exitProg(ifccParser.ProgContext ctx);
	/**
	 * Enter a parse tree produced by the {@code declaration}
	 * labeled alternative in {@link ifccParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterDeclaration(ifccParser.DeclarationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code declaration}
	 * labeled alternative in {@link ifccParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitDeclaration(ifccParser.DeclarationContext ctx);
	/**
	 * Enter a parse tree produced by the {@code instruction}
	 * labeled alternative in {@link ifccParser#statement}.
	 * @param ctx the parse tree
	 */
	void enterInstruction(ifccParser.InstructionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code instruction}
	 * labeled alternative in {@link ifccParser#statement}.
	 * @param ctx the parse tree
	 */
	void exitInstruction(ifccParser.InstructionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code declStd}
	 * labeled alternative in {@link ifccParser#declarationRule}.
	 * @param ctx the parse tree
	 */
	void enterDeclStd(ifccParser.DeclStdContext ctx);
	/**
	 * Exit a parse tree produced by the {@code declStd}
	 * labeled alternative in {@link ifccParser#declarationRule}.
	 * @param ctx the parse tree
	 */
	void exitDeclStd(ifccParser.DeclStdContext ctx);
	/**
	 * Enter a parse tree produced by the {@code declAff}
	 * labeled alternative in {@link ifccParser#declarationRule}.
	 * @param ctx the parse tree
	 */
	void enterDeclAff(ifccParser.DeclAffContext ctx);
	/**
	 * Exit a parse tree produced by the {@code declAff}
	 * labeled alternative in {@link ifccParser#declarationRule}.
	 * @param ctx the parse tree
	 */
	void exitDeclAff(ifccParser.DeclAffContext ctx);
	/**
	 * Enter a parse tree produced by the {@code returnStmt}
	 * labeled alternative in {@link ifccParser#instructionRule}.
	 * @param ctx the parse tree
	 */
	void enterReturnStmt(ifccParser.ReturnStmtContext ctx);
	/**
	 * Exit a parse tree produced by the {@code returnStmt}
	 * labeled alternative in {@link ifccParser#instructionRule}.
	 * @param ctx the parse tree
	 */
	void exitReturnStmt(ifccParser.ReturnStmtContext ctx);
	/**
	 * Enter a parse tree produced by the {@code affectation}
	 * labeled alternative in {@link ifccParser#instructionRule}.
	 * @param ctx the parse tree
	 */
	void enterAffectation(ifccParser.AffectationContext ctx);
	/**
	 * Exit a parse tree produced by the {@code affectation}
	 * labeled alternative in {@link ifccParser#instructionRule}.
	 * @param ctx the parse tree
	 */
	void exitAffectation(ifccParser.AffectationContext ctx);
	/**
	 * Enter a parse tree produced by {@link ifccParser#declStdRule}.
	 * @param ctx the parse tree
	 */
	void enterDeclStdRule(ifccParser.DeclStdRuleContext ctx);
	/**
	 * Exit a parse tree produced by {@link ifccParser#declStdRule}.
	 * @param ctx the parse tree
	 */
	void exitDeclStdRule(ifccParser.DeclStdRuleContext ctx);
	/**
	 * Enter a parse tree produced by {@link ifccParser#declAffRule}.
	 * @param ctx the parse tree
	 */
	void enterDeclAffRule(ifccParser.DeclAffRuleContext ctx);
	/**
	 * Exit a parse tree produced by {@link ifccParser#declAffRule}.
	 * @param ctx the parse tree
	 */
	void exitDeclAffRule(ifccParser.DeclAffRuleContext ctx);
	/**
	 * Enter a parse tree produced by {@link ifccParser#affectationRule}.
	 * @param ctx the parse tree
	 */
	void enterAffectationRule(ifccParser.AffectationRuleContext ctx);
	/**
	 * Exit a parse tree produced by {@link ifccParser#affectationRule}.
	 * @param ctx the parse tree
	 */
	void exitAffectationRule(ifccParser.AffectationRuleContext ctx);
	/**
	 * Enter a parse tree produced by {@link ifccParser#returnStmtRule}.
	 * @param ctx the parse tree
	 */
	void enterReturnStmtRule(ifccParser.ReturnStmtRuleContext ctx);
	/**
	 * Exit a parse tree produced by {@link ifccParser#returnStmtRule}.
	 * @param ctx the parse tree
	 */
	void exitReturnStmtRule(ifccParser.ReturnStmtRuleContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprMultDiv}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprMultDiv(ifccParser.ExprMultDivContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprMultDiv}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprMultDiv(ifccParser.ExprMultDivContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprAddSub}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprAddSub(ifccParser.ExprAddSubContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprAddSub}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprAddSub(ifccParser.ExprAddSubContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprVar}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprVar(ifccParser.ExprVarContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprVar}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprVar(ifccParser.ExprVarContext ctx);
	/**
	 * Enter a parse tree produced by the {@code exprConst}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExprConst(ifccParser.ExprConstContext ctx);
	/**
	 * Exit a parse tree produced by the {@code exprConst}
	 * labeled alternative in {@link ifccParser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExprConst(ifccParser.ExprConstContext ctx);
}